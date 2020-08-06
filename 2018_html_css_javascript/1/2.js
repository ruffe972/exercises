"use strict"

// From StackOverflow
if (!String.format) {
	String.format = function(format) {
		var args = Array.prototype.slice.call(arguments, 1);
		return format.replace(/{(\d+)}/g, function(match, number) { 
			return typeof args[number] != 'undefined'
				? args[number] 
				: match
			;
		});
	};
}

function parseDecimal(x) {
	return parseInt(x, 10);
}

function readAndSolveEquations() {
	var input_lines = ["a*x + b*y = c",
					   "d*x + e*y = f",
					   "Введите a, b, c, d, e, f через пробел."
					   ];
	var input = prompt(input_lines.join("\n"));
	var numbers = input.split(' ').map(parseDecimal);
	var matrix = [[numbers[0], numbers[1]],
				  [numbers[3], numbers[4]]];
	var freeCoeffs = [numbers[2], numbers[5]];
	var solution = solveEquations(matrix, freeCoeffs);
	if (solution == null) {
		var answer_message = "Нет однозначного решения системы.";
	} else {
		var x = solution[0];
		var y = solution[1];
		var answer_message = String.format("Решение: x = {0}; y = {1}", x, y);
	}
	var output_lines = [String.format("{0}x + {1}y = {2}", numbers[0], numbers[1], numbers[2]),
						String.format("{0}x + {1}y = {2}", numbers[3], numbers[4], numbers[5]),
						answer_message];
	alert(output_lines.join("\n"));
}

function determinant(matrix) {
	return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

function solveEquations(matrix, freeCoeffs) {
	var main_det = determinant(matrix);
	if (main_det == 0) {
		return null;
	}
	var x_matrix = [[freeCoeffs[0], matrix[0][1]],
				   [freeCoeffs[1], matrix[1][1]]];
	var x = 1 / main_det * determinant(x_matrix);
	var y_matrix = [[matrix[0][0], freeCoeffs[0]],
				   [matrix[1][0], freeCoeffs[1]]];
	var y = 1 / main_det * determinant(y_matrix);
	return [x, y];
}