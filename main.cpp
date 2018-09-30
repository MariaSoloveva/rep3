#include <iostream>
#include "sharedptr.hpp"
#include <string>

int main()
{
    SharedPtr<std::string> ptr;
    SharedPtr<std::string> ptr2;
    ptr.reset();
    ptr2.swap(ptr);
    swap(ptr, ptr2);
    std::cout << !ptr << std::endl;
    std::cout << bool(ptr) << std::endl;
    std::cout << ptr2.get() << std::endl;
    std::cout << (ptr != nullptr_t) << std::endl;
    std::cout << (nullptr_t != ptr) << std::endl;
    std::cout << (nullptr_t == ptr2) << std::endl;
    std::cout << (ptr2 == nullptr_t) << std::endl;
    return 0;
}
