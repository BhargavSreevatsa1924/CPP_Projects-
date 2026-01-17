#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    cache.put("name", "Bhargav");
    cache.put("role", "C++ Developer");

    std::cout << cache.get("name") << std::endl;
    cache.put("company", "Startup");

    std::cout << cache.get("role") << std::endl; // Evicted
    return 0;
}
