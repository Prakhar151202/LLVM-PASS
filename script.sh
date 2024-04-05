#!/bin/bash

# Compile Python script (if necessary)
# If the Python script needs compilation, put the commands here.

# Execute Python script
chmod 777 script.py
python3 ./script.py

# Compile LLVM Pass
clang -S -emit-llvm input.cpp -o input.ll
clang++ -shared -o MemoryUsagePass.so MemoryUsagePass.cpp `llvm-config --cxxflags --ldflags --libs` -fPIC

# Run LLVM analysis and generate DOT files
opt -load ./MemoryUsagePass.so -memory-usage < input.ll > /dev/null -enable-new-pm=0

