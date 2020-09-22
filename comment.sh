#!/bin/bash

rm "$2.cpp" >>  /dev/null 2>&1
cp "template.cpp" "$2.cpp"
comment="/*
\t	$1 \n\n
\t	Created by Carlos Sanchez \n \n
\t	Created at $(date)
*/
"
echo -e "$comment \n$(cat $2.cpp)" > $2.cpp

vim "$2.cpp" -c ":exec 156 | startinsert"
