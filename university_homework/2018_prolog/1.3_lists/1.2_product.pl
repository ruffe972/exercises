product([Head], Head) :- !.
product([Head|Tail], Product) :-
	product(Tail, TailProduct),
	Product is Head * TailProduct.

/** <examples>
?- product([1, 0, 3], X).
?- product([], X).
?- product([3], X).
?- product([4, 3.4], X).
?- product([2, 3, 4], X).
*/
