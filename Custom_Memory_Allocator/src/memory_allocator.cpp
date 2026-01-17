#include <iostream>
#include <cstdlib>

class MemoryAllocator {
private:
    char* memory;
    size_t size;
    size_t offset;

public:
    MemoryAllocator(size_t totalSize) {
        memory = (char*)std::malloc(totalSize);
        size = totalSize;
        offset = 0;
    }

    void* allocate(size_t bytes) {
        if (offset + bytes > size)
            return nullptr;

        void* ptr = memory + offset;
        offset += bytes;
        return ptr;
    }

    ~MemoryAllocator() {
        std::free(memory);
    }
};

int main() {
    MemoryAllocator allocator(1024);

    int* a = (int*)allocator.allocate(sizeof(int));
    *a = 10;

    std::cout << "Allocated value: " << *a << std::endl;
    return 0;
}
