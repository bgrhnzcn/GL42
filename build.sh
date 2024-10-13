#! /bin/bash

# Build script for GL42

cmake -S . -B build && make -C build/ 2> error.log