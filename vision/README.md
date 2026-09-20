# Subha's DSA Study Dashboard

A local study dashboard for the Striver-style DSA practice repository. It organizes C and C++ solutions by topic, tracks reviewed files, explains common problem patterns, and provides a separate local code runner.

## Features

- Topic-based DSA roadmap
- Search across topics and source files
- Folder workspace for every DSA topic
- Readable problem names generated from filenames
- Problem descriptions and solution approaches
- Per-file progress bars and reviewed status
- Topic-level progress tracking
- Study dates and current streak history
- Collapsible VS Code-style source editor
- Separate C/C++ code runner page
- JSON-backed problem descriptions with difficulty and category tags
- Custom stdin test input and CodeMirror C++ syntax highlighting
- Automated tests for discovery, metadata, progress wiring, and execution
- Progress saved locally in the browser with `localStorage`
- Automatic discovery of `.cpp`, `.c++`, and `.c` files

## Project Structure

```text
vision/
├── pages/
│   ├── index.html          # Main DSA dashboard
│   ├── topic.html          # Topic and file workspace
│   └── runner.html         # Separate code runner page
├── scripts/
│   ├── script.js           # Dashboard search and topic progress
│   ├── topic.js            # Topic files, descriptions, and tracking
│   └── runner-page.js      # Runner page file selection and execution
├── styles/
│   ├── style.css           # Shared dashboard styles
│   ├── topic.css           # Topic workspace styles
│   └── runner-page.css     # Runner page styles
├── runner-server.js        # Local server, file API, and C++ runner
├── .gitignore
└── README.md
```

## Requirements

- Node.js
- `g++` available in your PATH
- Windows users can use MinGW's `g++.exe`

The default Windows compiler path is:

```text
C:\MinGW\bin\g++.exe
```

To use another compiler, set the `CXX` environment variable before starting the server.

## Run Locally

From the `vision` folder:

```powershell
node runner-server.js
```

Open the dashboard:

```text
http://localhost:4173/vision/
```

Open the standalone runner:

```text
http://localhost:4173/vision/runner.html
```

The server discovers source files from the parent DSA repository automatically.

## Test Locally

From the parent repository:

```powershell
npm --prefix vision run check
npm --prefix vision test
```

When a file is marked reviewed, its completion timestamp and study date are stored in browser `localStorage`. The workspace uses those dates to calculate the current consecutive-day streak. Progress is intentionally local and is not synced to GitHub.

## Important Note

The dashboard and runner are designed for local use. A static host such as GitHub Pages can display the dashboard, but it cannot compile or execute C++ code. The local Node server is required for file discovery and code execution.
