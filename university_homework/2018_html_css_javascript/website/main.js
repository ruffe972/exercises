'use strict';

var POPUP_ANIM_TIME = 400;

// From StackOverflow
if (!String.format) {
    String.format = function(format) {
        var args = Array.prototype.slice.call(arguments, 1);
        return format.replace(/{(\d+)}/g, function(match, number) {
            return typeof args[number] != 'undefined'
                ? args[number]
                : match;
        });
    };
}

function main() {
    $('#banner_column img').click(function() {
        window.open('https://www.airbnb.com');
    });

    $('#about_link').click(function(event) {
        event.preventDefault();
        togglePopup($('#about_popup'));
    });
    $('#about_popup button, #about_popup .popup_bg').click(function() {
        togglePopup($('#about_popup'));
    });
    $('#login_form button').click(function(event) {
        event.preventDefault();
    });
}

function togglePopup($popupContainer) {
    var $popupBg = $popupContainer.children('.popup_bg');
    if ($popupBg.is(':animated')) {
        return;
    }
    var appearing = $popupContainer.css('display') == 'none';

    // toggle popup container
    var finalDisplayProp = appearing ? 'flex' : 'none';
    var changeDisplayProp = function() {
        $popupContainer.css('display', finalDisplayProp);
    }
    if (appearing) {
        changeDisplayProp();
    } else {
        setTimeout(changeDisplayProp, POPUP_ANIM_TIME);
    }

    // bg
    var finalOpacity = appearing ? 1 : 0;
    $popupBg.animate({opacity: finalOpacity}, POPUP_ANIM_TIME);

    //window
    var $window = $popupContainer.children('.popup_window');
    $window.toggleClass('appearing');
}

main();
