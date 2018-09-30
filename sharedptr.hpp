#include <iostream>
#include <atomic>

template <typename T>
class SharedPtr
{
    T* object;
    size_t inner;
public:
    SharedPtr() = default;
    ~SharedPtr() = default;
    SharedPtr(const SharedPtr& ptr)
    : object(ptr.object),
    inner(ptr.inner)
    {
        ++inner;
    }
    SharedPtr& operator=(const SharedPtr& ptr)
    {
        if (inner - 1 == 0)
        {
            if (object != nullptr)
            {
                delete ptr;
            }
            --inner;
        }
        object = ptr.object;
        inner = ptr.inner;
        ++inner;
        return *this;
    }
    void reset()
    {
        object = nullptr;
        --inner;
    }
    void reset(T* obj)
    {
        object = obj;
        --inner;                         // Точно так?
    }
    void swap(SharedPtr& ptr)
    {
        SharedPtr copy = *this;
        *this = ptr;
        ptr = copy;
    }
    T* get()
    {
        return object;
    }
    T& operator*() const
    {
        return *object;
    }
    T* operator->() const
    {
        return object;
    }
    // возвращает количество объектов shared_ptr, которые ссылаются на тот же управляемый объект
    size_t use_count() const
    {
        return inner;
    }
    // проверяет, указывает ли указатель на объект
    operator bool() const
    {
        return inner > 0;
    }
};
