#include "sharedPtr.hpp"


template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
        : object(ptr)
{
    counter->Increase();
}
template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& ptr)
        : object(ptr.object),
          counter(ptr.counter)
{
    counter->Increase();
}
template<typename T>
SharedPtr<T>::~SharedPtr()
{
    reset();
}
template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& ptr)
{
    if (this != ptr)
    {
        reset();
        object = ptr.object;
        counter = ptr.counter;
        counter->Increase();
    }
    return *this;
}
template<typename T>
void SharedPtr<T>::reset()
{
    counter->Decrease();
    if (counter->Get() == 0)
    {
        object = nullptr;
    }
}
template<typename T>
void SharedPtr<T>::reset(T* obj)
{
    SharedPtr<T>(obj).swap(object);
    counter->Decrease();
}
template<typename T>
void SharedPtr<T>::swap(SharedPtr& ptr)
{
    SharedPtr copy = *this;
    *this = ptr;
    ptr = copy;
}
template<typename T>
T* SharedPtr<T>::get()
{
    return object;
}
template<typename T>
T& SharedPtr<T>::operator*() const
{
    return *object;
}
template<typename T>
T* SharedPtr<T>::operator->() const
{
    return object;
}
template<typename T>
size_t SharedPtr<T>::use_count() const
{
    return static_cast<size_t>(counter->Get());
}
template<typename T>
SharedPtr<T>::operator bool() const
{
    return object != nullptr;
}

