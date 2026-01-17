# In-Memory Key-Value Store (C++)

A Redis-like in-memory key-value store implemented using C++ and STL.

## Features
- O(1) GET and SET operations
- LRU cache eviction policy
- Efficient memory usage
- Clean object-oriented design

## Concepts Used
- STL (unordered_map, list)
- OOP principles
- Memory optimization
- Hashing

## Build & Run
```bash
g++ src/main.cpp src/LRUCache.cpp -o kvstore
./kvstore
