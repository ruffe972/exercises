"use strict";

function main() {
    $("table").hover(toggleTableStyle);
}

function toggleTableStyle() {
    $("table").toggleClass("alternative");
}

main();

