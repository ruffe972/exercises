'use strict'

// createRange(3, 5) returns [3, 4]
function createRange(l, r) {
    return Array(r - l)
        .fill()
        .map((_, index) => l + index);
}

/**
 * Implement the solution in this function
 *
 * @param {number} n Output goes from 1 to n
 * @returns {(number|string)[]} An array containing all numbers and strings
 */
function fizzbuzz(n) {
    return createRange(1, n + 1).map((it) => {
        return it % 15 == 0
            ? 'FizzBuzz'
            : it % 5 == 0
                ? 'Buzz'
                : it % 3 == 0
                    ? 'Fizz'
                    : it
    });
}