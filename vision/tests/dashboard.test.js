const assert = require("node:assert/strict");
const fs = require("node:fs");
const path = require("node:path");
const { discoverFiles } = require("../runner-server");

const visionRoot = path.resolve(__dirname, "..");
const files = discoverFiles();
const metadata = JSON.parse(fs.readFileSync(path.join(visionRoot, "problems.json"), "utf8"));
const topicScript = fs.readFileSync(path.join(visionRoot, "scripts", "topic.js"), "utf8");

assert.ok(files.length > 0, "source file discovery should return files");
assert.ok(files.some((file) => file.path === "02-sorting/01-bubble.cpp"), "sorting file should be discoverable");
assert.ok(metadata.concepts.length > 0, "problem metadata should not be empty");
assert.ok(metadata.concepts.every((concept) => concept.category && concept.difficulty), "every concept needs category and difficulty");
assert.match(topicScript, /trackingProgress/, "topic page should update the progress bar");
assert.match(topicScript, /localStorage\.setItem\(progressKey/, "review progress should persist locally");
assert.match(topicScript, /studyDatesKey/, "topic page should persist study dates");
assert.match(topicScript, /currentStreak/, "topic page should calculate study streaks");

console.log(`Dashboard checks passed: ${files.length} source files, ${metadata.concepts.length} metadata entries.`);
