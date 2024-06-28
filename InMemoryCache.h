#ifndef INMEMORYCACHE_H
#define INMEMORYCACHE_H

#include <unordered_map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include "Cache.h"
#include "EvictionPolicy.h"

template<typename Key, typename Value>
class InMemoryCache : public Cache<Key, Value> {
private:
    size_t maxSize;
    std::unordered_map<Key, Value> cacheMap;
    std::unique_ptr<EvictionPolicy<Key>> evictionPolicy;
    std::mutex cacheMutex;

public:
    InMemoryCache(size_t size, std::unique_ptr<EvictionPolicy<Key>> policy);
    void put(const Key& key, const Value& value);
    Value get(const Key& key);
    void remove(const Key& key);
};

#include "InMemoryCache.cpp"

#endif // INMEMORYCACHE_H
