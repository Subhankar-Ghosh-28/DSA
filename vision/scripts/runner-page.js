const runnerBase =
  window.location.protocol === "file:" ? "http://localhost:4173" : "";
const $ = (selector) => document.querySelector(selector);
let sourceFiles = [];
let visibleFiles = [];

function displayFileName(file) {
  const stem = file.name.replace(/\.[^.]+$/, "").replace(/^\d+[._-]*/, "");
  let title = stem
    .replace(/([a-z0-9])([A-Z])/g, "$1 $2")
    .replace(/[_-]+/g, " ")
    .replace(/\s+/g, " ")
    .trim()
    .toLowerCase();
  if (
    file.path.startsWith("02-sorting/") &&
    /^(bubble|insertion|selection|merge|quick)$/.test(title)
  )
    title += " sort";
  return title.replace(/\b\w/g, (letter) => letter.toUpperCase());
}

function fillFiles() {
  const query = $("#runnerSearch").value.toLowerCase();
  visibleFiles = sourceFiles.filter((file) =>
    file.path.toLowerCase().includes(query),
  );
  $("#runnerFileSelect").innerHTML = visibleFiles.length
    ? visibleFiles
        .map(
          (file) =>
            `<option value="${file.path}">${displayFileName(file)} · ${file.path}</option>`,
        )
        .join("")
    : "<option>No matching files</option>";
  loadSelectedFile();
}

async function loadSelectedFile() {
  const path = $("#runnerFileSelect").value;
  const file = sourceFiles.find((source) => source.path === path);
  if (!file) return;
  const response = await fetch(
    `${runnerBase}/api/file?path=${encodeURIComponent(path)}`,
  );
  $("#selectedPath").textContent = file.path;
  $("#codeEditor").value = await response.text();
}

$("#runnerSearch").addEventListener("input", fillFiles);
$("#runnerFileSelect").addEventListener("change", loadSelectedFile);
$("#clearOutput").addEventListener("click", () => {
  $("#runnerOutput").textContent = "Output cleared.";
});
$("#runCodeButton").addEventListener("click", async () => {
  const path = $("#runnerFileSelect").value;
  const button = $("#runCodeButton");
  if (!path || !path.includes(".")) return;
  button.disabled = true;
  $("#runnerOutput").textContent = "Compiling and running...";
  try {
    const response = await fetch(`${runnerBase}/api/run`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ path, code: $("#codeEditor").value }),
    });
    const result = await response.json();
    $("#runnerOutput").textContent =
      result.output || result.error || "Program finished with no output.";
  } catch (error) {
    $("#runnerOutput").textContent =
      "Runner server is offline. Start: node vision/runner-server.js";
  } finally {
    button.disabled = false;
  }
});

fetch(`${runnerBase}/api/files`)
  .then((response) => response.json())
  .then((files) => {
    sourceFiles = files;
    fillFiles();
  })
  .catch(() => {
    $("#runnerFileSelect").innerHTML =
      "<option>Runner server is offline</option>";
    $("#runnerOutput").textContent =
      "Start the runner with: node vision/runner-server.js";
  });
