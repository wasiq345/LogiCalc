#!/bin/bash
set -e  # stop if any command fails
rm -rf bin
mkdir bin
g++ src/*.cpp -Iinclude -o bin/main
chmod +x bin/main
echo "✅ Build successful: bin/main created"
