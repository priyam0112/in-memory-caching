#ifndef LIFO_H
#define LIFO_H

#include <stack>
#include <unordered_set>
#include "EvictionPolicy.h"

template<typename Key>
class LIFOPolicy : public EvictionPolicy<Key> {
private:
    std::stack<Key> stack;
    std::unordered_set<Key> keySet;
public:
    void keyAccessed(const Key& key) override;
    Key evictKey() override;
};

#include "LIFO.cpp"

#endif // LIFO_H
