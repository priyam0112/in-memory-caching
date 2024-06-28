#include "InMemoryCache.h"

template<typename Key, typename Value>
InMemoryCache<Key, Value>::InMemoryCache(size_t size, std::unique_ptr<EvictionPolicy<Key>> policy)
    : maxSize(size), evictionPolicy(std::move(policy)) {}

template<typename Key, typename Value>
void InMemoryCache<Key, Value>::put(const Key& key, const Value& value) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    if (cacheMap.size() >= maxSize) {
        Key evictKey = evictionPolicy->evictKey();
        cacheMap.erase(evictKey);
    }
    cacheMap[key] = value;
    evictionPolicy->keyAccessed(key);
}

template<typename Key, typename Value>
Value InMemoryCache<Key, Value>::get(const Key& key) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    if (cacheMap.find(key) == cacheMap.end()) {
        throw std::runtime_error("Key not found");
    }
    evictionPolicy->keyAccessed(key);
    return cacheMap[key];
}

template<typename Key, typename Value>
void InMemoryCache<Key, Value>::remove(const Key& key) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    cacheMap.erase(key);
}
