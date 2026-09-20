const topics = [
  {
    id: "patterns",
    name: "Patterns",
    description: "Build your problem-solving instincts.",
    folder: "../01-pattern/",
    count: 23,
  },
  {
    id: "sorting",
    name: "Sorting",
    description: "Arrange data with confidence.",
    folder: "../02-sorting/",
    count: 5,
  },
  {
    id: "recursion",
    name: "Recursion & backtracking",
    description: "Think in smaller, repeatable states.",
    folder: "../03-recursion/",
    count: 23,
  },
  {
    id: "arrays",
    name: "Arrays",
    description: "Master the most important data structure.",
    folder: "../04-array/",
    count: 29,
  },
  {
    id: "vectors",
    name: "Vectors",
    description: "Get fluent with dynamic sequences.",
    folder: "../05-vector/",
    count: 12,
  },
  {
    id: "binary-search",
    name: "Binary search",
    description: "Cut search space in half.",
    folder: "../06-BinarySearch/",
    count: 25,
  },
  {
    id: "linked-list",
    name: "Linked list",
    description: "Navigate pointers and connections.",
    folder: "../07-linkedlist/",
    count: 18,
  },
  {
    id: "bit",
    name: "Bit manipulation",
    description: "Make every bit count.",
    folder: "../08-bit%20manipulation/",
    count: 12,
  },
  {
    id: "stack-queue",
    name: "Stack & queue",
    description: "Choose the right order of operations.",
    folder: "../09-stack-and-queue/",
    count: 22,
  },
  {
    id: "hashing",
    name: "Hashing",
    description: "Trade memory for speed.",
    folder: "../10-hash/",
    count: 15,
  },
  {
    id: "sliding-window",
    name: "Sliding window",
    description: "Turn nested loops into linear scans.",
    folder: "../11-slidingWindow/",
    count: 14,
  },
  {
    id: "strings",
    name: "Strings",
    description: "Read, transform, and compare text.",
    folder: "../12-string/",
    count: 20,
  },
  {
    id: "binary-tree",
    name: "Binary tree",
    description: "Traverse hierarchical thinking.",
    folder: "../13-BinaryTree/",
    count: 30,
  },
  {
    id: "bst",
    name: "Binary search tree",
    description: "Keep ordered data balanced.",
    folder: "../14-Biinary%20search%20tree/",
    count: 18,
  },
  {
    id: "heaps",
    name: "Heaps",
    description: "Always find the next best choice.",
    folder: "../15-Heaps/",
    count: 16,
  },
  {
    id: "greedy",
    name: "Greedy algorithms",
    description: "Make the best local decision.",
    folder: "../16-greedy%20algo/",
    count: 15,
  },
];

const storageKey = "striver-dsa-progress";
let progress = JSON.parse(localStorage.getItem(storageKey) || "{}");
const $ = (selector) => document.querySelector(selector);

function completedProblems() {
  return Object.values(progress).reduce(
    (sum, value) =>
      sum +
      (value ? topics.find((topic) => topic.id === value.id)?.count || 0 : 0),
    0,
  );
}

function updateStats() {
  const completed = completedProblems();
  const total = topics.reduce((sum, topic) => sum + topic.count, 0);
  const percent = Math.round((completed / total) * 100);
  $("#completedCount").textContent = completed;
  $("#totalCount").textContent = total;
  $("#remainingCount").textContent = total - completed;
  $("#overallPercent").textContent = `${percent}%`;
  $("#ringPercent").textContent = `${percent}%`;
  $("#overallProgress").style.width = `${percent}%`;
  $(".progress-ring").style.background =
    `conic-gradient(var(--green) ${percent * 3.6}deg, rgba(38,113,91,.13) 0deg)`;
  $("#activeCount").textContent = `${Object.keys(progress).length} active`;
  $("#weekCount").textContent = `${completed} problems`;
  $("#streakCount").textContent = completed ? "1 day" : "0 days";
}

function renderTopics() {
  const query = $("#searchInput").value.toLowerCase();
  const filter = $("#filterSelect").value;
  const visible = topics.filter((topic) => {
    const done = Boolean(progress[topic.id]?.done);
    return (
      topic.name.toLowerCase().includes(query) &&
      (filter === "all" ||
        (filter === "done" && done) ||
        (filter === "todo" && !done) ||
        (filter === "active" && progress[topic.id]))
    );
  });
  $("#topicGrid").innerHTML = visible
    .map((topic) => {
      const done = Boolean(progress[topic.id]?.done);
      return `<article class="topic-card ${done ? "completed" : ""}"><div class="topic-top"><span class="topic-number">${String(topics.indexOf(topic) + 1).padStart(2, "0")}</span><span class="topic-status">${done ? "Complete" : progress[topic.id] ? "In progress" : "Not started"}</span></div><h3>${topic.name}</h3><p>${topic.description}</p><div class="topic-bottom"><a class="topic-link" href="${topic.folder}">Open folder ↗</a><label class="check-wrap"><input type="checkbox" data-topic="${topic.id}" ${done ? "checked" : ""}> Done</label></div></article>`;
    })
    .join("");
  $("#emptyState").hidden = visible.length > 0;
  updateStats();
}

$("#topicGrid").addEventListener("change", (event) => {
  if (!event.target.matches("input[data-topic]")) return;
  const id = event.target.dataset.topic;
  progress[id] = { id, done: event.target.checked };
  if (!event.target.checked) delete progress[id];
  localStorage.setItem(storageKey, JSON.stringify(progress));
  renderTopics();
});
$("#searchInput").addEventListener("input", renderTopics);
$("#filterSelect").addEventListener("change", renderTopics);
$("#resetProgress").addEventListener("click", () => {
  if (Object.keys(progress).length && confirm("Reset all saved progress?")) {
    progress = {};
    localStorage.removeItem(storageKey);
    renderTopics();
  }
});
$("#todayLabel").textContent = new Intl.DateTimeFormat("en", {
  month: "short",
  day: "numeric",
  year: "numeric",
})
  .format(new Date())
  .toUpperCase();
renderTopics();

const runnerBase = window.location.protocol === "file:" ? "http://localhost:4173" : "";
const fileProgressKey = "striver-dsa-file-progress";
let sourceFiles = [];
let fileProgress = JSON.parse(localStorage.getItem(fileProgressKey) || "{}");

function updateFileStats() {
  const completed = Object.values(fileProgress).filter(Boolean).length;
  const total = sourceFiles.length;
  const percent = total ? Math.round((completed / total) * 100) : 0;
  $("#fileCompletedCount").textContent = completed;
  $("#fileTotalCount").textContent = total;
  $("#filePercent").textContent = `${percent}%`;
  $("#fileProgress").style.width = `${percent}%`;
}

function renderFiles() {
  const query = $("#fileSearchInput").value.toLowerCase();
  const filter = $("#fileFilterSelect").value;
  const visible = sourceFiles.filter((file) => {
    const done = Boolean(fileProgress[file.path]);
    return file.path.toLowerCase().includes(query) &&
      (filter === "all" || (filter === "done" && done) || (filter === "todo" && !done));
  });
  $("#fileList").innerHTML = visible.length ? visible.map((file, index) => `
    <div class="file-row">
      <span class="file-index">${String(index + 1).padStart(3, "0")}</span>
      <span class="file-name" title="${file.path}">${file.name}</span>
      <span class="file-folder">${file.folder}</span>
      <a class="file-open" href="${runnerBase}/api/file?path=${encodeURIComponent(file.path)}" target="_blank">Open ↗</a>
      <label class="file-check"><input type="checkbox" data-file="${file.path}" ${fileProgress[file.path] ? "checked" : ""}> Reviewed</label>
    </div>`).join("") : "<p class='loading-state'>No files match this filter.</p>";
  updateFileStats();
}

async function loadSourceFiles() {
  try {
    const response = await fetch(`${runnerBase}/api/files`);
    if (!response.ok) throw new Error("Runner server unavailable");
    sourceFiles = await response.json();
    $("#runnerFileSelect").innerHTML = sourceFiles.map((file) => `<option value="${file.path}">${file.path}</option>`).join("");
    renderFiles();
    await loadSelectedFile();
  } catch (error) {
    $("#fileList").innerHTML = "<p class='loading-state'>Start the runner with <strong>node vision/runner-server.js</strong> to discover and run every file.</p>";
    $("#runnerFileSelect").innerHTML = "<option>Runner server is offline</option>";
    $("#runnerOutput").textContent = "Runner server is offline. Start it from the workspace root with: node vision/runner-server.js";
  }
}

async function loadSelectedFile() {
  const path = $("#runnerFileSelect").value;
  if (!path || !path.includes(".")) return;
  const response = await fetch(`${runnerBase}/api/file?path=${encodeURIComponent(path)}`);
  $("#codeEditor").value = await response.text();
}

$("#fileSearchInput").addEventListener("input", renderFiles);
$("#fileFilterSelect").addEventListener("change", renderFiles);
$("#fileList").addEventListener("change", (event) => {
  if (!event.target.matches("input[data-file]")) return;
  const path = event.target.dataset.file;
  if (event.target.checked) fileProgress[path] = true;
  else delete fileProgress[path];
  localStorage.setItem(fileProgressKey, JSON.stringify(fileProgress));
  updateFileStats();
});
$("#runnerFileSelect").addEventListener("change", loadSelectedFile);
$("#clearOutput").addEventListener("click", () => { $("#runnerOutput").textContent = "Output cleared."; });
$("#runCodeButton").addEventListener("click", async () => {
  const button = $("#runCodeButton");
  button.disabled = true;
  $("#runnerOutput").textContent = "Compiling and running...";
  try {
    const response = await fetch(`${runnerBase}/api/run`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ path: $("#runnerFileSelect").value, code: $("#codeEditor").value }),
    });
    const result = await response.json();
    $("#runnerOutput").textContent = result.output || result.error || "Program finished with no output.";
  } catch (error) {
    $("#runnerOutput").textContent = "Could not connect to the runner server. Start: node vision/runner-server.js";
  } finally {
    button.disabled = false;
  }
});
loadSourceFiles();
