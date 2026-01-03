let opended = false;

const cppFiles =  [
    "01triangle.cpp",
    "batterfly.cpp",
    "pattern12.cpp",
    "01triangle.cpp",
    "diamond.cpp",
    "square.cpp",
];

function toggleFolder() {
    const div = document.getElementById("patternFiles");

    if(!opended) {
        div.innerHTML = "";
        cppFiles.forEach(file => {
            const link = document.createElement("a");
            link.href = `../01-pattern/${file}`;
            link.textContent = file;
            link.target = "";
            div.appendChild(link);
        });
        div.style.display = "block";
    }
    else {
        div.style.display = "none";
    }

    opended = ! opended;
}