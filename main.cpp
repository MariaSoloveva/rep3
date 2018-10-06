#include <iostream>
#include <exception>
#include <iomanip>

#include "json.hpp"
using json =  nlohmann::json;


kson redistributionOfJson(json& input)
{
    json array = json::array();
    json obj = json::object();
    for (size_t inner = 0; inner < input.size(); ++inner)
    {
        size_t i = 0;
        obj["ticker"] = input[i][inner];
        ++i;
        obj["id"] = input[i][inner];
        ++i;
        obj["description"] = input[i][inner];
        array.push_back(obj);
    }
    return array;
}

int main() {
    const char * const json_data = R"(
[
["Si-9.15", "RTS-9.15", "GAZP-9.15"],
[100024, 100027, 100050],
["Futures contract for USD/RUB", "Futures contract for index RTS", "Futures contract for Gazprom shares"]
]
)";
    json input;
    input = json::parse(json_data);
    json output  = redistributionOfJson(input);
    std::cout << output.size();
    return 0;
}
