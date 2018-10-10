#include <iostream>
#include <gtest/gtest.h>
#include "sharedPtr.hpp"

#include <memory>
#include <iostream>

struct St {
    St() { std::cout << "St...\n"; }
    ~St() { std::cout << "~St...\n"; }
};

struct D {
    void operator()(St* p) const {
        std::cout << "Call delete for St object...\n";
        delete p;
    }
};

int main()
{
    // constructor with no managed object
    std::shared_ptr<St> sh1;

    // constructor with object
    std::shared_ptr<St> sh2(new St);
    std::shared_ptr<St> sh3(sh2);
    std::cout << sh2.use_count() << '\n';
    std::cout << sh3.use_count() << '\n';

    //constructor with object and deleter
    std::shared_ptr<St> sh4(new St, D());
}