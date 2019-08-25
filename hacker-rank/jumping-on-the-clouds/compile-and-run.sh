#!/bin/bash

set -x

g++ main.cpp -W -Wall -std=c++14 -O3 && for f in input*.txt; do cat "$f" | ./a.out; done;

