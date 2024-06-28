#ifndef EVICTIONPOLICY_H
#define EVICTIONPOLICY_H

template<typename Key>
class EvictionPolicy {
public:
    virtual ~EvictionPolicy() = default;
    virtual void keyAccessed(const Key& key) = 0;
    virtual Key evictKey() = 0;
};

#endif // EVICTIONPOLICY_H
