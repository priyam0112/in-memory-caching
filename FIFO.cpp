#include "FIFO.h"

template<typename Key>
void FIFOPolicy<Key>::keyAccessed(const Key& key) {
    if (keySet.find(key) == keySet.end()) {
        queue.push(key);
        keySet.insert(key);
    }
}

template<typename Key>
Key FIFOPolicy<Key>::evictKey() {
    Key key = queue.front();
    queue.pop();
    keySet.erase(key);
    return key;
}
