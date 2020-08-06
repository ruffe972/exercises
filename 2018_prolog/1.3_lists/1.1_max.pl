two_numbers_max(Num1, Num2, Num1) :- Num1 > Num2.
two_numbers_max(Num1, Num2, Num2) :- Num1 =< Num2.

/* list_max(List, Max) */
list_max([Head], Head) :- !.
list_max([Head|Tail], Max) :-
    list_max(Tail, TailMax),
    two_numbers_max(Head, TailMax, Max).

/** <examples>
?- list_max([3, 1, 2], X).
?- list_max([], X).
?- list_max([1, 2, 3], X).
*/
