reversed_binary(Number, [Number]) :- Number < 2, !.
reversed_binary(Number, [Digit | DigitsTail]) :-
    Digit is Number mod 2,
    SmallerNumber is Number div 2,
    reversed_binary(SmallerNumber, DigitsTail).

binary(Number, Digits) :-
	reversed_binary(Number, ReversedDigits),
    reverse(ReversedDigits, Digits).

list_of_zeros_helper(_, _, 0) :- !.
list_of_zeros_helper(ZerosLength, [0 | TailZeros], Counter) :-
	TailZerosLength is ZerosLength - 1,
	TailCounter is Counter - 1,
	list_of_zeros_helper(TailZerosLength, TailZeros, TailCounter).
	
list_of_zeros(ZerosLength, Zeros) :- list_of_zeros_helper(ZerosLength, Zeros, ZerosLength).

binary_with_zero_padding(Number, Digits) :-
	binary(Number, DigitsWithNoPadding),
	length(DigitsWithNoPadding, DigitsWithNoPaddingLength),
	ZerosLength is 16 - DigitsWithNoPaddingLength,
	ZerosLength >= 0,
	list_of_zeros(ZerosLength, Zeros),
	append(Zeros, DigitsWithNoPadding, Digits).

/** <examples>
?- binary_with_zero_padding(256, Digits).
?- binary_with_zero_padding(258, Digits).
?- binary_with_zero_padding(1024, Digits).
?- binary_with_zero_padding(65535, Digits).
?- binary_with_zero_padding(65534, Digits).
*/
