const runnerBase =
  window.location.protocol === "file:" ? "http://localhost:4173" : "";
const params = new URLSearchParams(window.location.search);
const folder = params.get("folder") || "01-pattern";
const $ = (selector) => document.querySelector(selector);
const progressKey = "striver-dsa-file-progress";
let files = [];
let selectedFile = null;
let reviewed = JSON.parse(localStorage.getItem(progressKey) || "{}");

const topicNames = {
  "01-pattern": [
    "Patterns",
    "Build visual and logical problem-solving instincts.",
  ],
  "02-sorting": ["Sorting", "Compare, divide, and arrange data efficiently."],
  "03-recursion": [
    "Recursion & backtracking",
    "Break a problem into smaller states and explore choices.",
  ],
  "04-array": ["Arrays", "Build the core techniques for contiguous data."],
  "05-vector": [
    "Vectors",
    "Practice dynamic sequences and container operations.",
  ],
  "06-BinarySearch": [
    "Binary search",
    "Reduce an ordered search space with a precise invariant.",
  ],
  "07-linkedlist": [
    "Linked list",
    "Follow and modify relationships between nodes.",
  ],
  "08-bit manipulation": [
    "Bit manipulation",
    "Use binary representation to solve problems cleanly.",
  ],
  "09-stack-and-queue": [
    "Stack & queue",
    "Model last-in-first-out and first-in-first-out workflows.",
  ],
  "10-hash": ["Hashing", "Use constant-time lookup to trade memory for speed."],
  "11-slidingWindow": [
    "Sliding window",
    "Maintain a useful range while scanning once.",
  ],
  "12-string": [
    "Strings",
    "Transform, compare, and parse sequences of characters.",
  ],
  "13-BinaryTree": [
    "Binary tree",
    "Traverse hierarchical data and reason about subtrees.",
  ],
  "14-Biinary search tree": [
    "Binary search tree",
    "Keep ordered values searchable through tree structure.",
  ],
  "15-Heaps": [
    "Heaps",
    "Keep the smallest or largest candidate available efficiently.",
  ],
  "16-greedy algo": [
    "Greedy algorithms",
    "Make a locally optimal choice and prove why it works.",
  ],
};

const concepts = [
  {
    keys: ["bubble"],
    problem:
      "Compare neighboring values and repeatedly move the largest unsorted value to the end.",
    solution:
      "Scan adjacent pairs, swap inverted values, and stop early when a pass makes no swap. Time O(n²), space O(1).",
  },
  {
    keys: ["insertion"],
    problem:
      "Insert each new value into its correct position in the sorted prefix.",
    solution:
      "Shift larger prefix values right until the insertion point is found. Time O(n²), space O(1).",
  },
  {
    keys: ["selection"],
    problem:
      "Select the smallest remaining value and place it at the next output position.",
    solution:
      "Search the unsorted suffix for the minimum and swap once per position. Time O(n²), space O(1).",
  },
  {
    keys: ["merge"],
    problem:
      "Sort a sequence by splitting it, solving both halves, and merging ordered results.",
    solution:
      "Use divide and conquer with two pointers during merge. Time O(n log n), space O(n).",
  },
  {
    keys: ["quick"],
    problem:
      "Partition values around a pivot so recursive ranges become smaller.",
    solution:
      "Place elements on the correct side of a pivot, then recurse on both partitions. Average O(n log n), stack O(log n).",
  },
  {
    keys: ["binary", "search"],
    problem:
      "Find a target or boundary in sorted data without scanning every element.",
    solution:
      "Maintain a closed search interval and discard half after each comparison. Time O(log n), space O(1).",
  },
  {
    keys: ["rotate"],
    problem:
      "Move values around a circular boundary while preserving their relative order.",
    solution:
      "Use reverse operations or modular indexing to move the segments in place. Time O(n), space O(1).",
  },
  {
    keys: ["two", "sum"],
    problem: "Find two values whose combined result matches a target.",
    solution:
      "Store previously seen values in a hash map and look up each complement. Average O(n), space O(n).",
  },
  {
    keys: ["palindrom", "palindrome"],
    problem: "Check whether a sequence reads the same from both directions.",
    solution:
      "Compare mirrored positions while moving inward. Time O(n), space O(1) when done in place.",
  },
  {
    keys: ["subsequence"],
    problem:
      "Generate or count valid subsequences while preserving element order.",
    solution:
      "At each index, branch into take and skip decisions, then combine valid states.",
  },
  {
    keys: ["tree", "traversal"],
    problem:
      "Visit every node in the required order and process its subtree results.",
    solution:
      "Choose recursive or stack-based DFS/BFS according to the traversal order. Time O(n), space O(h) for DFS.",
  },
  {
    keys: ["heap", "kth"],
    problem:
      "Maintain the best k candidates while processing a stream or collection.",
    solution:
      "Use a min or max heap so insertion and removal stay O(log k); total O(n log k).",
  },
  {
    keys: ["window", "substring"],
    problem:
      "Find the longest or shortest valid contiguous range under a constraint.",
    solution:
      "Expand the right edge, repair the constraint from the left, and track the best range. Time O(n).",
  },
  {
    keys: ["stock", "profit"],
    problem: "Choose buy and sell moments to maximize a permitted gain.",
    solution:
      "Track the best previous buying price and update the best gain in one pass. Time O(n), space O(1).",
  },
  {
    keys: ["parenthes", "bracket"],
    problem:
      "Determine whether opening and closing symbols form a valid nesting sequence.",
    solution:
      "Push openings and match every closing symbol against the stack top. Time O(n), space O(n).",
  },
  {
    keys: ["permutation", "permuation"],
    problem:
      "Arrange all values into valid orderings without losing or repeating choices.",
    solution:
      "Track used positions and backtrack after each complete choice sequence.",
  },
  {
    keys: ["prime", "sieve"],
    problem: "Identify prime numbers or factor a value efficiently.",
    solution:
      "Mark multiples from each unmarked base up to the square root. Sieve time O(n log log n).",
  },
];

function getConcept(file) {
  const normalized = file.name.toLowerCase().replace(/[_-]/g, " ");
  return (
    concepts.find((concept) =>
      concept.keys.every((key) => normalized.includes(key)),
    ) || {
      problem: `Study the ${file.name.replace(/\.[^.]+$/, "").replace(/[_-]/g, " ")} problem and identify its input, output, and constraints.`,
      solution:
        "Read the implementation line by line, write down the invariant it maintains, then verify the time and space complexity with a small example.",
    }
  );
}

function renderList() {
  const query = $("#problemSearch").value.toLowerCase();
  const visible = files.filter((file) =>
    file.name.toLowerCase().includes(query),
  );
  $("#problemList").innerHTML = visible.length
    ? visible
        .map(
          (file) =>
            `<button class="problem-item ${reviewed[file.path] ? "done" : ""} ${selectedFile?.path === file.path ? "selected" : ""}" data-path="${file.path}"><strong>${file.name}</strong><small>${reviewed[file.path] ? "Reviewed" : "Ready to study"}</small></button>`,
        )
        .join("")
    : "<p class='loading-state'>No matching files.</p>";
  $("#topicCompleted").textContent = files.filter(
    (file) => reviewed[file.path],
  ).length;
  $("#topicTotal").textContent = files.length;
}

async function chooseFile(file) {
  selectedFile = file;
  const response = await fetch(
    `${runnerBase}/api/file?path=${encodeURIComponent(file.path)}`,
  );
  $("#topicEditor").value = await response.text();
  const concept = getConcept(file);
  $("#problemTitle").textContent = file.name.replace(/\.[^.]+$/, "");
  $("#selectedPath").textContent = file.path;
  $("#problemDescription").textContent = concept.problem;
  $("#problemSolution").textContent = concept.solution;
  $("#reviewedCheck").checked = Boolean(reviewed[file.path]);
  renderList();
}

async function loadTopic() {
  const response = await fetch(`${runnerBase}/api/files`);
  files = (await response.json()).filter((file) =>
    file.path.startsWith(`${folder}/`),
  );
  const [name, subtitle] = topicNames[folder] || [
    folder,
    "Explore the source files in this topic.",
  ];
  $("#topicTitle").textContent = name;
  $("#topicSubtitle").textContent = subtitle;
  renderList();
  if (files[0]) chooseFile(files[0]);
}

$("#problemSearch").addEventListener("input", renderList);
$("#problemList").addEventListener("click", (event) => {
  const button = event.target.closest("[data-path]");
  if (button)
    chooseFile(files.find((file) => file.path === button.dataset.path));
});
$("#reviewedCheck").addEventListener("change", (event) => {
  if (!selectedFile) return;
  if (event.target.checked) reviewed[selectedFile.path] = true;
  else delete reviewed[selectedFile.path];
  localStorage.setItem(progressKey, JSON.stringify(reviewed));
  renderList();
});
$("#clearTopicOutput").addEventListener("click", () => {
  $("#topicOutput").textContent = "Output cleared.";
});
$("#runTopicCode").addEventListener("click", async () => {
  if (!selectedFile) return;
  const button = $("#runTopicCode");
  button.disabled = true;
  $("#topicOutput").textContent = "Compiling and running...";
  try {
    const response = await fetch(`${runnerBase}/api/run`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        path: selectedFile.path,
        code: $("#topicEditor").value,
      }),
    });
    const result = await response.json();
    $("#topicOutput").textContent =
      result.output || result.error || "Program finished with no output.";
  } catch (error) {
    $("#topicOutput").textContent =
      "Runner server is offline. Start: node vision/runner-server.js";
  }
  button.disabled = false;
});
loadTopic().catch(() => {
  $("#problemList").innerHTML =
    "<p class='loading-state'>Start the runner server to open this workspace.</p>";
});
