#!/bin/bash

set -x

clang++ main.cpp -W -Wall -std=c++17 -O2 -fsanitize=address && for f in input*.txt; do cat "$f" | ./a.out; done;
