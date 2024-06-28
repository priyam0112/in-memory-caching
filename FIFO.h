#ifndef FIFO_H
#define FIFO_H

#include <queue>
#include <unordered_set>
#include "EvictionPolicy.h"

template<typename Key>
class FIFOPolicy : public EvictionPolicy<Key> {
private:
    std::queue<Key> queue;
    std::unordered_set<Key> keySet;
public:
    void keyAccessed(const Key& key) override;
    Key evictKey() override;
};

#include "FIFO.cpp"

#endif // FIFO_H
