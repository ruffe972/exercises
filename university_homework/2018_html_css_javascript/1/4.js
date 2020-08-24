"use strict"

// From StackOverflow
if (!String.format) {
	String.format = function(format) {
		var args = Array.prototype.slice.call(arguments, 1);
		return format.replace(/{(\d+)}/g, function(match, number) { 
			return typeof args[number] != "undefined"
				? args[number] 
				: match
			;
		});
	};
}

main()

function min(array) {
	if (array.length == 1) {
		return array[0];
	}
	return Math.min(array[0], min(array.slice(1)));
}

function main() {
	var array = [1, -2, -45, 6, 3, 1, 0, 0, -45, 6];
	alert(String.format("Массив: [{0}].\nМинимальный элемент: {1}.", array, min(array)));
}
