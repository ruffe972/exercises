word_and_letters(melon, e, o).
word_and_letters(onion, n, o).
word_and_letters(esper, s, e).
word_and_letters(tenor, e, o).
word_and_letters(cream, r, a).
word_and_letters(start, t, r).
word_and_letters(flare, l, r).
word_and_letters(sport, p, r).
word_and_letters(index, n, e).
word_and_letters(bread, r, a).
word_and_letters(steam, t, a).
word_and_letters(grass, r, s).
word_and_letters(twist, w, s).
word_and_letters(shame, h, m).
word_and_letters(human, u, a).
word_and_letters(mouse, o, s).
word_and_letters(sleep, l, e).
word_and_letters(crest, r, s).
word_and_letters(cross, r, s).
word_and_letters(death, e, t).
word_and_letters(honor, o, o).

suitable_words(TW, BW, LW, RW) :-
    dif(TW, BW), dif(TW, LW), dif(TW, RW), dif(BW, LW), dif(BW, RW), dif(LW, RW),
    word_and_letters(TW, TLC, TRC), word_and_letters(LW, TLC, BLC),
    word_and_letters(BW, BLC, BRC), word_and_letters(RW, TRC, BRC).

/** <examples>
?- suitable_words(TopWord, BottomWord, LeftWord, RightWord).
*/
