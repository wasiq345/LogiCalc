#!/bin/bash
echo "🚀 Building C++ engine..."

mkdir -p bin

# Compile all .cpp files in src/ into one executable
g++ src/*.cpp -o bin/main -std=c++17

chmod +x bin/main
echo "✅ Build complete."
