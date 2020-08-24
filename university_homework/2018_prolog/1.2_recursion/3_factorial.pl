factorial(0, 1) :- !.
factorial(X, Y) :-
    NewX is X - 1,
    factorial(NewX, NewY),
    Y is NewY * X.

recursive_factorial_helper(0, Factorial, Factorial).
recursive_factorial_helper(Counter, Factorial, Accumulator) :-
    Counter > 0,
    SmallerCounter is Counter - 1,
    NewAccumulator is Accumulator * Counter,
    recursive_factorial_helper(SmallerCounter, Factorial, NewAccumulator).

recursive_factorial(N, Factorial) :- recursive_factorial_helper(N, Factorial, 1).

/** <examples>
?- factorial(0, X).
?- factorial(5, X).
?- factorial(10000, X).
?- recursive_factorial(0, X).
?- recursive_factorial(5, X).
?- recursive_factorial(10000, X).
?- recursive_factorial(100000, X).
*/
