"use strict"

var EXAMS_DATE = new Date(2017, 11, 17);
var SECONDS_IN_MINUTE = 60;
var MINUTES_IN_HOUR = 60;
var HOURS_IN_DAY = 24;

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

function main() {
	updateTimer();
	setInterval(updateTimer, 1000);
}

function updateTimer() {
	document.getElementById("timer").textContent = remainingTimeString();
}

function remainingTimeString() {
	var presentDate = new Date();
	var totalTimeInMilliSeconds = Math.max(0, EXAMS_DATE.getTime() - presentDate.getTime());
	var totalTime = Math.floor(totalTimeInMilliSeconds / 1000);
	var seconds = totalTime % SECONDS_IN_MINUTE;
	totalTime = Math.floor(totalTime / SECONDS_IN_MINUTE);
	var minutes = totalTime % MINUTES_IN_HOUR;
	totalTime = Math.floor(totalTime / MINUTES_IN_HOUR);
	var hours = totalTime % HOURS_IN_DAY;
	totalTime = Math.floor(totalTime / HOURS_IN_DAY);
	var days = totalTime;
	return String.format("{0} дн, {1} ч, {2} мин, {3} сек", days, hours, minutes, seconds);
}
