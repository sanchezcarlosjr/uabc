#!/bin/bash

rm "$1.cpp" >>  /dev/null 2>&1
cp "template.cpp" "$1.cpp"
comment="/*
\t	$1 \n\n
\t	Created by Carlos Sanchez \n \n
\t	Created at $(date)
*/
"
echo -e "$comment \n$(cat $1.cpp)" > $1.cpp

function addLine() {
	touch temp.cpp
	sed -e "/$1() {/i /*\n \t$3 \n*/" $2.cpp >> temp.cpp
	mv temp.cpp $2.cpp
	rm temp.cpp
}

addLine "program1" $1 $2
addLine "program2" $1 $3
addLine "program3" $1 $4
vim "$1.cpp" -c ":exec 23 | startinsert"

