#!/bin/bash

# 192. Word Frequency
# https://leetcode.com/problems/word-frequency/

cat words.txt | xargs | sed 's/ /\n/g' | sort | uniq -c | sort -n -r | awk '{ print $2 " " $1 }'
