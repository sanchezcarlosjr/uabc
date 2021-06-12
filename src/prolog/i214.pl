:- op(100,xf,holds).

question(X,Y,Z) :- Y holds,write(X),write(" "),write(Y),write(" "),write(Z).

Y holds :- fact(Y).

fact(Y) :- the_problem_is_stated_as(Y).

the_problem_is_stated_as(there_are_five_hats).
the_problem_is_stated_as(three_of_them_are_white_two_are_black).
