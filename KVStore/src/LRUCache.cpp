#include "LRUCache.h"

LRUCache::LRUCache(int cap) : capacity(cap) {}

std::string LRUCache::get(const std::string& key) {
    if (map.find(key) == map.end())
        return "NOT FOUND";

    cache.splice(cache.begin(), cache, map[key]);
    return map[key]->second;
}

void LRUCache::put(const std::string& key, const std::string& value) {
    if (map.find(key) != map.end()) {
        cache.erase(map[key]);
    }

    cache.push_front({key, value});
    map[key] = cache.begin();

    if (cache.size() > capacity) {
        auto last = cache.back();
        map.erase(last.first);
        cache.pop_back();
    }
}

void LRUCache::remove(const std::string& key) {
    if (map.find(key) == map.end()) return;
    cache.erase(map[key]);
    map.erase(key);
}
