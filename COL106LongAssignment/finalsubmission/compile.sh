#!/bin/bash

# This script compiles all C++ source files (.cpp) in the current
# directory into a single executable named 'main'.

# -std=c++17: Enforces the C++17 standard for modern features.
# -g: Includes debugging symbols, which is good practice.
# -o main: Names the final executable file 'main'.
# *.cpp: A wildcard that automatically finds all .cpp files to compile.

echo "Compiling the Time-Travelling File System..."
g++ -std=c++17 -g -o main *.cpp

# This part checks if the compilation succeeded or failed.
if [ $? -eq 0 ]; then
    echo "Compilation successful! Executable created: 'main'"
    echo "To run the program, use the command: ./main"
else
    echo "Compilation failed. Please check the error messages above."
fi