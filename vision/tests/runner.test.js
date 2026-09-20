const assert = require("node:assert/strict");
const { spawn } = require("node:child_process");
const path = require("node:path");

const root = path.resolve(__dirname, "..");
const port = 4174;
const serverProcess = spawn(process.execPath, [path.join(root, "runner-server.js")], { cwd: root, env: { ...process.env, PORT: String(port) }, stdio: "ignore" });

async function waitForServer() {
  for (let attempt = 0; attempt < 30; attempt += 1) {
    try { await fetch(`http://localhost:${port}/api/files`); return; } catch { await new Promise((resolve) => setTimeout(resolve, 100)); }
  }
  throw new Error("runner server did not start");
}

(async () => {
  try {
    await waitForServer();
    const files = await fetch(`http://localhost:${port}/api/files`).then((response) => response.json());
    assert.ok(files.length > 0, "API should discover source files");
    const response = await fetch(`http://localhost:${port}/api/run`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ path: files[0].path, code: '#include <iostream>\nint main(){ int value; std::cin >> value; std::cout << value * 2; }', input: "21\n" }),
    });
    const result = await response.json();
    assert.match(result.output, /42/, "runner should pass stdin to the compiled program");
    console.log(`Runner checks passed: discovered ${files.length} files and stdin execution works.`);
  } finally {
    serverProcess.kill();
  }
})().catch((error) => { console.error(error); process.exitCode = 1; });
