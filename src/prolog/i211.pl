male(terach).
male(abraham).
male(nachor).
male(haran).
male(isaac).
male(lot).
male(luis).

female(sarah).
female(milcah).
female(yiscah).
female(maria).
female(abigail).

parent(terach,abraham). 
parent(terach,nachor).
parent(terach,haran).
parent(abraham,isaac).
parent(haran,lot).
parent(haran,milcah).
parent(haran,yiscah).
parent(sarah, isaac).
parent(maria,abraham).
parent(maria,nachor).
parent(maria, terach).
parent(milcah,haran).
parent(abraham, luis).

grandparent(Ancestor, Descendant) :- parent(Ancestor, Child), parent(Child, Descendant).
grandmother(Ancestor, Descendant) :- grandparent(Ancestor, Descendant), female(Ancestor).
grandfather(Ancestor, Descendant) :- grandparent(Ancestor, Descendant), male(Ancestor).
mother(Mother,Kid) :- parent(Mother,Kid), female(Mother).
father(Father,Kid) :- parent(Father,Kid), male(Father).
sibling(X,Y) :- parent(Parent, X), parent(Parent, Y), X \== Y.
brother(X,Y) :- sibling(X,Y), male(X).
sister(X,Y) :- sibling(X,Y), female(X).
child(Kid,Parent) :- parent(Parent,Kid).
son(Kid,Parent) :- child(Kid, Parent), male(Kid).
daughter(Kid,Parent) :- child(Kid,Parent), female(Kid).
uncle(X,Person) :- brother(X,Sibling), parent(Sibling,Person).
aunt(X,Person) :- sister(X,Sibling), parent(Sibling,Person).
twin(X,Y) :- sibling(X,Y), ovum(X,Y).
