const http = require("http");
const fs = require("fs");
const path = require("path");
const os = require("os");
const { spawn } = require("child_process");

const workspaceRoot = path.resolve(__dirname, "..");
const port = Number(process.env.PORT || 4173);
const allowedExtensions = new Set([".cpp", ".c++", ".c"]);
const ignoredFolders = new Set([".git", ".cph", "vision", "node_modules"]);

function discoverFiles(folder = workspaceRoot, files = []) {
  for (const entry of fs.readdirSync(folder, { withFileTypes: true })) {
    if (entry.isDirectory() && !ignoredFolders.has(entry.name)) discoverFiles(path.join(folder, entry.name), files);
    if (entry.isFile() && allowedExtensions.has(path.extname(entry.name).toLowerCase())) {
      const relative = path.relative(workspaceRoot, path.join(folder, entry.name)).split(path.sep).join("/");
      files.push({ path: relative, name: entry.name, folder: path.dirname(relative).replaceAll("/", " / ") });
    }
  }
  return files.sort((first, second) => first.path.localeCompare(second.path, undefined, { numeric: true }));
}

function safePath(relativePath) {
  const fullPath = path.resolve(workspaceRoot, relativePath || "");
  if (!fullPath.startsWith(workspaceRoot + path.sep) || !allowedExtensions.has(path.extname(fullPath).toLowerCase())) throw new Error("Invalid source file");
  return fullPath;
}

function send(response, status, body, type = "application/json") {
  response.writeHead(status, { "Content-Type": `${type}; charset=utf-8`, "Access-Control-Allow-Origin": "*" });
  response.end(type === "application/json" ? JSON.stringify(body) : body);
}

function runCode(code, extension, input, callback) {
  const tempFolder = fs.mkdtempSync(path.join(os.tmpdir(), "dsa-runner-"));
  const sourceFile = path.join(tempFolder, `main${extension === ".c" ? ".c" : ".cpp"}`);
  const executable = path.join(tempFolder, process.platform === "win32" ? "program.exe" : "program");
  fs.writeFileSync(sourceFile, code, "utf8");
  const compiler = process.env.CXX || (process.platform === "win32" ? "C:\\MinGW\\bin\\g++.exe" : "g++");
  const compile = spawn(compiler, [sourceFile, "-std=c++17", "-O2", "-o", executable]);
  let compileOutput = "";
  compile.stdout.on("data", (chunk) => { compileOutput += chunk; });
  compile.stderr.on("data", (chunk) => { compileOutput += chunk; });
  compile.on("error", (error) => callback(`Compiler error: ${error.message}`));
  compile.on("close", (code) => {
    if (code !== 0) return callback(compileOutput || `Compilation failed with exit code ${code}.`);
    const program = spawn(executable, [], { timeout: 5000 });
    let output = "";
    program.stdout.on("data", (chunk) => { output += chunk; });
    program.stderr.on("data", (chunk) => { output += chunk; });
    if (input) program.stdin.write(input);
    program.stdin.end();
    program.on("error", (error) => callback(`Runtime error: ${error.message}`));
    program.on("close", (exitCode) => callback(`${output}${output && !output.endsWith("\n") ? "\n" : ""}Exit code: ${exitCode}`));
  });
}

const server = http.createServer((request, response) => {
  const requestUrl = new URL(request.url, `http://${request.headers.host}`);
  if (requestUrl.pathname === "/api/files") return send(response, 200, discoverFiles());
  if (requestUrl.pathname === "/api/file" && request.method === "GET") {
    try { return send(response, 200, fs.readFileSync(safePath(requestUrl.searchParams.get("path")), "utf8"), "text/plain"); }
    catch (error) { return send(response, 400, { error: error.message }); }
  }
  if (requestUrl.pathname === "/api/run" && request.method === "POST") {
    let body = "";
    request.on("data", (chunk) => { body += chunk; if (body.length > 500000) request.destroy(); });
    request.on("end", () => {
      try {
        const payload = JSON.parse(body);
        safePath(payload.path);
        runCode(payload.code || "", path.extname(payload.path), payload.input || "", (output) => send(response, 200, { output }));
      } catch (error) { send(response, 400, { error: error.message }); }
    });
    return;
  }
  const aliases = {
    "/": "/vision/pages/index.html",
    "/vision/": "/vision/pages/index.html",
    "/vision/index.html": "/vision/pages/index.html",
    "/vision/topic.html": "/vision/pages/topic.html",
    "/vision/runner.html": "/vision/pages/runner.html",
  };
  const assetAlias = requestUrl.pathname === "/problems.json"
    ? "/vision/problems.json"
    : requestUrl.pathname.startsWith("/styles/") || requestUrl.pathname.startsWith("/scripts/")
    ? `/vision/${requestUrl.pathname.slice(1)}`
    : requestUrl.pathname;
  const requested = aliases[requestUrl.pathname] || assetAlias;
  let filePath = path.resolve(workspaceRoot, `.${requested}`);
  if (fs.existsSync(filePath) && fs.statSync(filePath).isDirectory()) filePath = path.join(filePath, "index.html");
  if (!filePath.startsWith(workspaceRoot) || !fs.existsSync(filePath)) return send(response, 404, "Not found", "text/plain");
  const types = { ".html": "text/html", ".css": "text/css", ".js": "text/javascript" };
  send(response, 200, fs.readFileSync(filePath), types[path.extname(filePath)] || "application/octet-stream");
});

if (require.main === module) {
  server.on("error", (error) => {
    if (error.code === "EADDRINUSE") {
      console.error(`Port ${port} is already in use. Open http://localhost:${port}/vision/ or stop the existing server before starting another.`);
      process.exitCode = 1;
      return;
    }
    console.error(error);
    process.exitCode = 1;
  });
  server.listen(port, () => console.log(`DSA runner: http://localhost:${port}/vision/`));
}

module.exports = { discoverFiles, safePath, server };