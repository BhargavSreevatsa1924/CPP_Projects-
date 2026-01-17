#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <list>
#include <string>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<std::string, std::string>> cache;
    std::unordered_map<std::string,
        std::list<std::pair<std::string, std::string>>::iterator> map;

public:
    LRUCache(int cap);
    std::string get(const std::string& key);
    void put(const std::string& key, const std::string& value);
    void remove(const std::string& key);
};

#endif
