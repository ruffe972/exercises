'use strict';

var CHECKBOX_SEL = 'input[type="checkbox"]';

var PRICES = {
    'borscht': 100,
    'sour_cream_for_borscht': 10,
    'dill_for_borscht': 10,
    'solyanka': 110,
    'lemon_for_solyanka': 10,
    'olives_for_solyanka': 10,
    'noodles': 60,
    'hamburger': 90,
};

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
    initMenuPrices();
    updateTotalPrice();
    $('.expander').click(onMenuItemClick);
    $('.menu ' + CHECKBOX_SEL).change(updateTotalPrice);
}

function updateTotalPrice() {
    var price = getListPrice($('ul.menu'));
    $('#total_price').text(String.format('Итого: {0} р.', price));
}

function getPriceFromCheckbox($checkbox) {
    if ($checkbox.is(CHECKBOX_SEL)) {
        return PRICES[$checkbox.prop('id')];
    }
    return 0;
}

function getListPrice($list) {
    var price = 0;
    if ($list) {
        $.each($list.children(), function(i, li) {
            price += getListItemPrice($(li));
        });
    }
    return price;
}

function getListItemPrice($listItem) {
    var $expander = null;
    var listItemIsEnabled = true;

    var $firstChild = $listItem.children().first();
    if ($firstChild.is('label')) {
        var $checkbox = $firstChild.children().first();
        listItemIsEnabled = $checkbox.prop('checked');
        $expander = $checkbox;
    } else if ($firstChild.is('.expander')) {
        $expander = $firstChild;
    }

    var price = 0;
    if (listItemIsEnabled) {
        price += getPriceFromCheckbox($expander);
        price += getListPrice($getExpandableList($expander));
    }
    return price;
}

function onMenuItemClick(event) {
    var $expander = $(event.target);
    var $list = $getExpandableList($expander);
    if ($list.is(":animated")) {
        event.preventDefault();
    } else {
        expandOrCollapse($list);
    }
}

function expandOrCollapse($element) {
    $element.toggleClass('show');
    if ($element.hasClass('show')) {
        // Calculate finalHeight
        $element.css('height', 'auto');
        var finalHeight = $element.height();
        $element.height(0);

        var finalOpacity = 1;
        var completion = function() {
            $element.css('height', 'auto');
        }
    } else {
        var finalHeight = 0;
        var finalOpacity = 0;
    }
    $element.animate({
        height: finalHeight,
        opacity: finalOpacity,
    }, 200, completion);
}

function $getExpandableList($expander) {
    if (!$expander.hasClass('expander')) {
        return null;
    }
    if ($expander.is('input')) {
        var $listNeighbor = $expander.parent();
    } else {
        var $listNeighbor = $expander;
    }
    return $listNeighbor.next();
}

function initMenuPrices() {
    for (var key in PRICES) {
        var $label = $('#' + key).parent();
        $label.append(String.format(' ({0} р.)', PRICES[key]));
    }
}

main();
