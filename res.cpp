#include <iostream>

template<class T>
class scoped_ptr
{
    T* scopedPtr;
public:
    scoped_ptr() = default;
    ~scoped_ptr() = default;
    scoped_ptr(scoped_ptr const & a)
    {
        scopedPtr = a.scopedPtr;
    }
    scoped_ptr& operator=(scoped_ptr const & a)
    {
        if (a != *this)
        {
            if (*this != nullptr)
                delete this;
            scopedPtr = a.scopedPtr;
        }
        return *this;
    }
    scoped_ptr& reset()
    {
        scopedPtr = nullptr;
    };
    T operator*()
    {
        T* tmp = *scopedPtr;
        return *tmp;
    }
    T* operator->()
    {
        return this->scopedPtr;
    }
    T* get() const
    {
        return this->scopedPtr;
    }
    scoped_ptr& swap(scoped_ptr & a)
    {
        scoped_ptr tmp = *this;
        *this = a;
        a = tmp;
    }
    bool operator! ()
    {
        return !(scopedPtr == nullptr);
    }
    explicit operator bool()
    {
        return !bool();
    }
};

template<class T>
inline bool operator==(scoped_ptr<T> const & p, std::nullptr_t) throw()
{

}

template<class T>
inline bool operator==(std::nullptr_t, scoped_ptr<T> const & p) throw()
{

}

template<class T>
inline bool operator!=(scoped_ptr<T> const & p, std::nullptr_t) throw()
{

}

template<class T>
inline bool operator!=(std::nullptr_t, scoped_ptr<T> const & p) throw()
{

}

template<class T>
inline void swap(scoped_ptr<T> & a, scoped_ptr<T> & b) throw()
{
    a.swap(b);
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T * get_pointer(scoped_ptr<T> const & p) throw()
{
    return p.get();
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
