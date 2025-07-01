#!/bin/sh
for dir in vendor/*/include; do
  INCLUDE_PATHS="$INCLUDE_PATHS -I$dir"
done
g++ src/*.cpp deps/*.a -o YOUR_APP ${INCLUDE_PATHS} -lGL -ldl -lpthread -lm -std=c++17 -Wall -Wextra -Wpedantic -O3 #max optimizations
