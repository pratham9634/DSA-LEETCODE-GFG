#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lru; // front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key not found
        if (cache.find(key) == cache.end()) 
            return -1;
        
        // Move this key-value to front (most recent)
        auto it = cache[key];
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        // If already exists, erase old position
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key]);
        } 
        // If full, remove least recently used
        else if (lru.size() == capacity) {
            auto last = lru.back();
            cache.erase(last.first);
            lru.pop_back();
        }

        // Insert new element at front
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
};
