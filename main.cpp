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
    std::cout << get_pointer(ptr2) << std::endl;
    std::cout << (ptr != nullptr) << std::endl;
    std::cout << (nullptr != ptr) << std::endl;
    std::cout << (nullptr == ptr2) << std::endl;
    std::cout << (ptr2 == nullptr) << std::endl;
    return 0;
}
