#include "LRU.h"

template<typename Key>
void LRUCachePolicy<Key>::keyAccessed(const Key& key) {
    if (keyMap.find(key) != keyMap.end()) {
        lruList.erase(keyMap[key]);
    }
    lruList.push_front(key);
    keyMap[key] = lruList.begin();
}

template<typename Key>
Key LRUCachePolicy<Key>::evictKey() {
    Key key = lruList.back();
    lruList.pop_back();
    keyMap.erase(key);
    return key;
}
