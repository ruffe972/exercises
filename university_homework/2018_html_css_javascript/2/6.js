'use strict';

function main() {
    var $enlargableImages = $('.enlargable_img');
    $enlargableImages.click(enlargeImage);
    $('#image_popup').click(onImagePopupClick);
    $enlargableImages.attr('title', 'Нажмите для увеличения');
}

function togglePopup($popup) {
    if ($popup.is(':animated')) {
        return;
    }
    var appearing = $popup.css('display') == 'none';
    var finalDisplayProp = appearing ? 'flex' : 'none';
    var finalOpacity = appearing ? 1 : 0;
    var changeDisplayProp = function() {
        $popup.css('display', finalDisplayProp);
    }
    if (appearing) {
        changeDisplayProp()
    }
    $popup.animate({opacity: finalOpacity}, 300, function() {
        if (!appearing) {
            changeDisplayProp()
        }
    });
}

function enlargeImage(event) {
    var $popup = $('#image_popup');
    var $clickedImage = $(event.target);
    var $enlargedImage = $popup.children('img');
    $enlargedImage.attr('src', $clickedImage.attr('src'));
    $enlargedImage.attr('alt', $clickedImage.attr('alt'));
    togglePopup($popup);
}

function onImagePopupClick(event) {
    togglePopup($('#image_popup'));
}

main();
