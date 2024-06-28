#ifndef LRU_H
#define LRU_H

#include <list>
#include <unordered_map>
#include "EvictionPolicy.h"

template<typename Key>
class LRUCachePolicy : public EvictionPolicy<Key> {
private:
    std::list<Key> lruList;
    std::unordered_map<Key, typename std::list<Key>::iterator> keyMap;
public:
    void keyAccessed(const Key& key) override;
    Key evictKey() override;
};

#include "LRU.cpp"

#endif // LRU_H
