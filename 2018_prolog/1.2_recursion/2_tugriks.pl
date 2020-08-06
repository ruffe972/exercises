initial_capital(30000).
mult(1.12).

final_capital_rec(0, Capital) :- initial_capital(Capital), !.
final_capital_rec(N, Capital) :-
    NewN is N - 1,
    final_capital_rec(NewN, NewCapital),
    mult(Mult),
    Capital is NewCapital * Mult.

final_capital(N, Capital) :-
    initial_capital(InitialCapital),
    mult(Mult),
    Capital is InitialCapital * (Mult ** N).

/** <examples>
?- final_capital(4, Capital).
?- final_capital_rec(4, Capital).
*/
