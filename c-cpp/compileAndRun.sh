#!/bin/bash

SRC=$1

g++ -g -Wall -Wextra -Werror -I .. ${SRC} && ./a.out
