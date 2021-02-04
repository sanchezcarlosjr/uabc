#!/bin/env bash
rm ./a.out
c++ -pthread -std=c++17 $1;
./a.out
