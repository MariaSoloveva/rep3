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
    return 0;
}
