"use strict";

function getCheckboxes() {
    return $("input[type=checkbox]").toArray();
}

function main() {
    var checkboxes = getCheckboxes();
    checkboxes[0].checked = true;
    checkboxes[1].checked = true;
    updateImages();
}

function updateImages() {
    var checked = getCheckboxes().map(function(x) { return x.checked });
    var paragraphs = $("p");
    for (var i = 0; i < checked.length; i++) {
        paragraphs[i].className = checked[i] ? "active" : "";
        paragraphs[i].innerHTML = "";
    }
    $('<img src="doge.jpg" alt="doge"/>').appendTo("p.active");
}

main();
