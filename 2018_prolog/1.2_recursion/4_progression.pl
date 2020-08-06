first_progression_member(20).
d(10).

nth_progression_member(1, Member) :- first_progression_member(Member), !.
nth_progression_member(N, Member) :-
    PreviousN is N - 1,
    d(D),
    nth_progression_member(PreviousN, PreviousProgressionMember),
    Member is PreviousProgressionMember + D.

nth_progression_member_tail_helper(1, Accumulator, Accumulator) :- !.
nth_progression_member_tail_helper(Counter, Member, Accumulator) :-
    d(D),
    NewCounter is Counter - 1,
    NewAccumulator is Accumulator + D,
    nth_progression_member_tail_helper(NewCounter, Member, NewAccumulator).

nth_progression_member_tail(N, Member) :-
    first_progression_member(FirstMember),
    nth_progression_member_tail_helper(N, Member, FirstMember).

/** <examples>
?- nth_progression_member(1, Member).
?- nth_progression_member(2, Member).
?- nth_progression_member(5, Member).
?- nth_progression_member(100000, Member).
?- nth_progression_member_tail(1, Member).
?- nth_progression_member_tail(2, Member).
?- nth_progression_member_tail(5, Member).
?- nth_progression_member_tail(100000, Member).
*/

