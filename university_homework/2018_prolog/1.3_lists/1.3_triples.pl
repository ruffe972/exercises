/* triples_product(List, Product) */
triples_product(List, 1) :-
	length(List, Length),
	Length < 3.
triples_product([Num1, Num2, Num3 | Tail], Product) :-
	triples_product(Tail, TailTriplesProduct),
	Product is (Num1 + Num2 + Num3) * TailTriplesProduct.

/** <examples>
?- triples_product([1, 0, 3], X).
?- triples_product([], X).
?- triples_product([4, 3.4], X).
?- triples_product([2, 3, 4, 5, 6], X).
?- triples_product([2, 3, 4, 5, 6, 1], X).
?- triples_product([2, 3, 4, 5, 6, 1, 0], X).
*/
