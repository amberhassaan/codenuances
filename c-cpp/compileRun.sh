#!/bin/bash
WARN=${2--Wall -Wextra };
g++ -g $WARN $1 && ./a.out
