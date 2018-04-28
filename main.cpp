#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include <cstring>
#include "catch.hpp"
#include "Bf.hpp"

TEST_CASE("test of constructors", "[file]")
{
    std::string s = "00001110";
    std::vector<bool> vec = {0, 0, 0, 0, 1, 1, 1, 0};
    std::initializer_list<bool> list = {0, 0, 0, 0, 1, 1, 1, 0};
    boolean_function bf1(vec);
    boolean_function bf2(s);
    REQUIRE(bf1 == bf2);
    REQUIRE(bf1 == boolean_function(list));
    REQUIRE(bf1 == boolean_function(bf2));
    std::string s1 = "11110000";
    boolean_function bf3(s1);
    bf2 = bf3;
    REQUIRE_FALSE(bf1 == bf2);
    REQUIRE(bf1 == boolean_function(14, 3));
    vec = {0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(boolean_function(vec) == bf1.zero(3));
    vec = {1, 1, 1, 1, 1, 1, 1, 1};
    REQUIRE(boolean_function(vec) == bf1.one(3));
    vec = {0, 1, 0, 1, 0, 1, 0, 1};
    REQUIRE(bf1.var(0, 3) == boolean_function(vec));
}
TEST_CASE("test of functions : '*', '|', '+'", "[file]")
{
    std::vector<bool> vec = {0, 0, 0, 0, 1, 1, 1, 0};
    boolean_function bf1(vec);
    REQUIRE((bf1 + bf1) == bf1.zero(3));
    REQUIRE((bf1 | bf1) == bf1);
    vec = {1, 1, 0, 0, 1, 1, 1, 0};
    boolean_function bf2(vec);
    vec = {1, 1, 0, 0, 0, 0, 0, 0};
    bf1 += bf2;
    REQUIRE((bf1 * bf2) == boolean_function(vec));
    REQUIRE(bf1 == boolean_function(vec));
    REQUIRE((bf1 * bf1) == bf1);
    vec = {1, 1, 0, 0, 1, 1, 1, 0};
    REQUIRE((bf1 | bf2) == boolean_function(vec));
    vec = {1, 1, 0, 0, 0, 0, 0};
    REQUIRE_THROWS_AS((bf1 | boolean_function(vec)), std::invalid_argument);
    REQUIRE_THROWS_AS(bf1 + boolean_function(vec), std::invalid_argument);
    REQUIRE_THROWS_AS(bf1 * boolean_function(vec), std::invalid_argument);
}
TEST_CASE("test of functions : '~', dimension, weight, is_balanced", "[file]")
{
    std::vector<bool> vec = {0, 0, 0, 0, 1, 1, 1, 0};
    boolean_function bf1(vec);
    REQUIRE(bf1.weight() == 3);
    REQUIRE(bf1.dimension() == 3);
    REQUIRE_FALSE(bf1.is_balanced());
    vec = {1, 1, 1, 1, 0, 0, 0, 1};
    REQUIRE(~bf1 == boolean_function(vec));
    vec = {0, 0, 0, 1, 1, 1, 1, 0};
    REQUIRE(boolean_function(vec).weight() == 4);
    REQUIRE(boolean_function(vec).is_balanced());
}
TEST_CASE("test of operator ()", "[file]")
{
    std::vector<bool> vec = {0, 0, 0, 0, 1, 1, 1, 0};
    std::vector<bool> vec1 = {1, 1, 0};
    REQUIRE(boolean_function (vec)(vec1) == 1);
    REQUIRE(boolean_function (vec)({1, 1, 0}) == 1);
    std::vector<boolean_function> vecOfBF;
    vecOfBF.push_back(boolean_function (vec));
    vecOfBF.push_back(boolean_function (vec1));
    vecOfBF.push_back(boolean_function (vec));
    vec1 = {1, 0, 1, 1, 0, 0, 1, 1};
    std::vector<bool> vec2 = {0, 1, 1, 1, 1, 1, 1, 1};
    REQUIRE(boolean_function (vec1)(vecOfBF) == boolean_function(vec2));
}
