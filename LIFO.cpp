#include "LIFO.h"

template<typename Key>
void LIFOPolicy<Key>::keyAccessed(const Key& key) {
    if (keySet.find(key) == keySet.end()) {
        stack.push(key);
        keySet.insert(key);
    }
}

template<typename Key>
Key LIFOPolicy<Key>::evictKey() {
    Key key = stack.top();
    stack.pop();
    keySet.erase(key);
    return key;
}
