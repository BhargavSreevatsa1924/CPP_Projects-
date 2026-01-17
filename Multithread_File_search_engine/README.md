# Multithreaded File Search Engine (C++)

A high-performance file search tool that uses multithreading to search
keywords across multiple files concurrently.

## Features
- Concurrent file processing
- Thread-safe output using mutex
- Faster search on large directories

## Concepts Used
- Multithreading
- Mutex and synchronization
- File I/O
- Performance optimization

## Build & Run
```bash
g++ src/main.cpp -pthread -o search
./search

“Test files simulate real-world logs and documentation to validate concurrent search performance.”