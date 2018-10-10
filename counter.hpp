#ifndef SHARED_PTR_COUNTER_H
#define SHARED_PTR_COUNTER_H

#include <atomic>

class Counter
{
    std::atomic_uint inner;
public:
    Counter() = default;
    ~Counter() = default;
    Counter& Increase()
    {
        ++inner;
        return *this;
    }
    Counter& Decrease()
    {
        --inner;
        return *this;
    }
    std::atomic_uint& Get()
    {
        return inner;
    }
};

#endif //SHARED_PTR_COUNTER_H
