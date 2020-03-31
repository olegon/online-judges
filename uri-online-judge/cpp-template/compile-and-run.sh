#!/bin/bash

set -x

g++ main.cpp -W -Wall -std=c++11 -O2 -lm && for f in input*.txt; do cat "$f" | ./a.out; done;
