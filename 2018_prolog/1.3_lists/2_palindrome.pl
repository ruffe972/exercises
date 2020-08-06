palindrome(List) :-
    reversed_list(List, ReversedList),
    List = ReversedList.

reversed_list_helper([], ReversedList, ReversedList) :- !.
reversed_list_helper([Head | Tail], ReversedList, Accumulator) :-
    reversed_list_helper(Tail, ReversedList, [Head|Accumulator]).

reversed_list(List, ReversedList) :- reversed_list_helper(List, ReversedList, []).

/** <examples>
?- palindrome([w, e, r]).
?- palindrome([w, e, w]).
?- palindrome([f]).
*/
