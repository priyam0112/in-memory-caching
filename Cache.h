#ifndef CACHE_H
#define CACHE_H

template<typename Key, typename Value>
class Cache {
public:
    virtual ~Cache() = default;
    virtual void put(const Key& key, const Value& value) = 0;
    virtual Value get(const Key& key) = 0;
    virtual void remove(const Key& key) = 0;
};

#endif // CACHE_H
