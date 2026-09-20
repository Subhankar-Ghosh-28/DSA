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
const runnerBase =
  window.location.protocol === "file:" ? "http://localhost:4173" : "";

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

function displayFileName(file) {
  const stem = file.name.replace(/\.[^.]+$/, "").replace(/^\d+[._-]*/, "");
  let title = stem
    .replace(/([a-z0-9])([A-Z])/g, "$1 $2")
    .replace(/[_-]+/g, " ")
    .replace(/\s+/g, " ")
    .trim()
    .toLowerCase();
  const aliases = {
    rat: "right angle triangle",
    ll: "linked list",
    bst: "binary search tree",
    nge: "next greater element",
    nse: "next smaller element",
    lca: "lowest common ancestor",
    atoi: "string to integer",
  };
  title = aliases[title] || title;
  if (
    file.path.startsWith("02-sorting/") &&
    /^(bubble|insertion|selection|merge|quick)$/.test(title)
  )
    title += " sort";
  return title.replace(/\b\w/g, (letter) => letter.toUpperCase());
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
      const folder = topic.folder.replace(/^\.\.\//, "").replace(/\/$/, "");
      return `<article class="topic-card ${done ? "completed" : ""}"><div class="topic-top"><span class="topic-number">${String(topics.indexOf(topic) + 1).padStart(2, "0")}</span><span class="topic-status">${done ? "Complete" : progress[topic.id] ? "In progress" : "Not started"}</span></div><h3>${topic.name}</h3><p>${topic.description}</p><div class="topic-bottom"><a class="topic-link" href="topic.html?folder=${encodeURIComponent(folder)}">Open workspace ↗</a><label class="check-wrap"><input type="checkbox" data-topic="${topic.id}" ${done ? "checked" : ""}> Done</label></div></article>`;
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

let sourceFiles = [];

function renderGlobalResults(query) {
  const results = $("#globalResults");
  if (!query.trim()) {
    results.hidden = true;
    return;
  }
  const normalized = query.toLowerCase();
  const topicResults = topics
    .filter((topic) =>
      `${topic.name} ${topic.description}`.toLowerCase().includes(normalized),
    )
    .map((topic) => {
      const folder = topic.folder.replace(/^\.\.\//, "").replace(/\/$/, "");
      return `<a class="global-result" href="topic.html?folder=${encodeURIComponent(folder)}"><span class="result-icon">▦</span><span><strong>${topic.name}</strong><small>Topic workspace · ${topic.count} problems</small></span><b>↗</b></a>`;
    });
  const fileResults = sourceFiles
    .filter((file) => file.path.toLowerCase().includes(normalized))
    .slice(0, 8)
    .map(
      (file) =>
        `<a class="global-result" href="topic.html?folder=${encodeURIComponent(file.folder.replaceAll(" / ", "/"))}&file=${encodeURIComponent(file.path)}"><span class="result-icon">{ }</span><span><strong>${displayFileName(file)}</strong><small>${file.path}</small></span><b>↗</b></a>`,
    );
  const allResults = [...topicResults, ...fileResults];
  results.innerHTML = allResults.length
    ? allResults.join("")
    : "<p class='no-results'>No topic or file found.</p>";
  results.hidden = false;
}

$("#globalSearch").addEventListener("input", (event) =>
  renderGlobalResults(event.target.value),
);
document.addEventListener("click", (event) => {
  if (!event.target.closest(".global-search-wrap"))
    $("#globalResults").hidden = true;
});

fetch(`${runnerBase}/api/files`)
  .then((response) => response.json())
  .then((files) => {
    sourceFiles = files;
  })
  .catch(() => {
    sourceFiles = [];
  });
