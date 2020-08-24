max(Num1, Num2, Num1) :- Num1 > Num2.
max(Num1, Num2, Num2) :- Num1 =< Num2.

sum_of_non_negative(Num1, Num2, Sum) :-
	max(Num1, 0, NonNegativeNum1),
	max(Num2, 0, NonNegativeNum2),
	Sum is NonNegativeNum1 + NonNegativeNum2.

list_sum_of_non_negative([], 0).
list_sum_of_non_negative([Head | Tail], Sum) :-
	list_sum_of_non_negative(Tail, TailSum),
	sum_of_non_negative(Head, TailSum, Sum).

/** <examples>
?- list_sum_of_non_negative([], X).
?- list_sum_of_non_negative([-1], X).
?- list_sum_of_non_negative([-1, -2, 0, -3], X).
?- list_sum_of_non_negative([1, 2, 3, 4], X).
?- list_sum_of_non_negative([1, -1, 0, 1.4], X).
*/