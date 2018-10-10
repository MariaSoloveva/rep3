#include <iostream>
#include "counter.hpp"

template <typename T>
class SharedPtr
{
    T *object = nullptr;
    Counter* counter;
public:
    SharedPtr() = default;

    ~SharedPtr();

    SharedPtr(T* ptr);

    SharedPtr(const SharedPtr<T> &ptr);

    SharedPtr<T> &operator=(const SharedPtr &ptr);

    void reset();

    void reset(T *);

    void swap(SharedPtr &);

    T *get();

    T &operator*() const;

    T *operator->() const;

    // возвращает количество объектов shared_ptr, которые ссылаются на тот же управляемый объект
    size_t use_count() const;

    // проверяет, указывает ли указатель на объект
    operator bool() const;
};