#include <iostream>
#include "parser.h"
#include <string>

int main() {
    std::string s = "{
    "lastname" : "Ivanov",
    "firstname" : "Ivan",
    "age" : 25,
    "islegal" : false,
    "marks" : [
    	4,5,5,5,2,3
    ],
    "address" : {
    	"city" : "Moscow",
        "street" : "Vozdvijenka"
    }
}";
    Json str(s);
    return 0;
}
