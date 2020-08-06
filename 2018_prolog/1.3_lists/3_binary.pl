reversed_binary(Number, [Number]) :- Number < 2, !.
reversed_binary(Number, [Digit | DigitsTail]) :-
    Digit is Number mod 2,
    SmallerNumber is Number div 2,
    reversed_binary(SmallerNumber, DigitsTail).

binary(Number, Digits) :-
	reversed_binary(Number, ReversedDigits),
    reverse(ReversedDigits, Digits).
	
/** <examples>
?- binary(0, [0]).
?- binary(0, Digits).
?- binary(1, [1]).
?- binary(1, Digits).
?- binary(2, [1, 0]).
?- binary(2, Digits).
?- binary(3, [1, 1]).
?- binary(3, Digits).
?- binary(5, [1, 0, 1]).
?- binary(5, Digits).
?- binary(256, [1, 0, 0, 0, 0, 0, 0, 0, 0]).
?- binary(256, Digits).
?- binary(258, [1, 0, 0, 0, 0, 0, 0, 1, 0]).
?- binary(258, Digits).
*/
