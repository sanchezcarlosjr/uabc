see(person1,person2,white).
see(person1,person3,black).
see(person2,person3).

person1Has(black) :-  see(person1,person2,white), see(person1,person3, white).
person1Has([white; black]).
