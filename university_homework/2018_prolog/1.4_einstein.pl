nationality(Nationality, [Nationality, _, _, _, _]).
color(Color, [_, Color, _, _, _]).
cigar(Cigar, [_, _, Cigar, _, _]).
animal(Animal, [_, _, _, Animal, _]).
drink(Drink, [_, _, _, _, Drink]).

neighbors(HouseA, HouseB, Houses) :- nextto(HouseA, HouseB, Houses).
neighbors(HouseA, HouseB, Houses) :- nextto(HouseB, HouseA, Houses).

/*
main :- Houses = [[norway, yellow, dunhill, cat, water],
                  [denmark, blue, rothmans, horse, tea],
                  [england, red, pallMall, bird, milk],
                  [germany, green, malboro, fish, coffee],
                  [sweden, white, philip_morris, dog, beer]],
*/                  
main :- Houses = [_, _, _, _, _],
    nationality(norway, HouseA), nth1(1, Houses, HouseA),
    color(red, HouseB), nationality(england, HouseB), member(HouseB, Houses),
    color(green, HouseC), color(white, HouseD), nextto(HouseC, HouseD, Houses),
    nationality(denmark, HouseE), drink(tea, HouseE), member(HouseE, Houses),
    cigar(rothmans, HouseF), animal(cat, HouseG), neighbors(HouseF, HouseG, Houses),
    color(yellow, HouseH), cigar(dunhill, HouseH), member(HouseH, Houses),
    nationality(germany, HouseI), cigar(malboro, HouseI), member(HouseI, Houses),
    drink(milk, HouseJ), nth1(3, Houses, HouseJ),
    cigar(rothmans, HouseK), drink(water, HouseL), neighbors(HouseK, HouseL, Houses),
    cigar(pallMall, HouseM), animal(bird, HouseM), member(HouseM, Houses),
    nationality(sweden, HouseN), animal(dog, HouseN), member(HouseN, Houses),
    nationality(norway, HouseO), color(blue, HouseP), neighbors(HouseO, HouseP, Houses),
    animal(horse, HouseQ), color(blue, HouseQ), member(HouseQ, Houses),
    cigar(philip_morris, HouseR), drink(beer, HouseR), member(HouseR, Houses),
    color(green, HouseS), drink(coffee, HouseS), member(HouseS, Houses).

/** <examples>
?- animal(cat, HouseT), nationality(CatOwner, HouseT), member(HouseT, Houses).
*/
