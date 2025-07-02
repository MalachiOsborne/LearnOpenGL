#!/bin/sh
for dir in vendor/*/include; do
  INCLUDE_PATHS="$INCLUDE_PATHS -I$dir"
done
g++ src/*.cpp src/glad.c deps/*.a ${INCLUDE_PATHS} -lGL -ldl -lpthread -lm -std=c++17 -Wall -Wextra -Wpedantic -O3 -o run #max optimizations
