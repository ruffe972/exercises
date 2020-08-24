"use strict";

function main() {
    $("label").click(onMenuItemClick);
}

function onMenuItemClick() {
    var $element = $("ul").first();
    if ($element.is(":animated")) {
        return;
    }
    $element.toggleClass("show");
    if ($element.hasClass("show")) {
        // Calculate finalHeight
        $element.css("height", "auto");
        var finalHeight = $element.height();
        $element.height(0);

        var finalOpacity = 1;
    } else {
        var finalHeight = 0;
        var finalOpacity = 0;
    }
    $element.animate({
        height: finalHeight,
        opacity: finalOpacity,
    });
}

main();
