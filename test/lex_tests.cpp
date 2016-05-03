#include "catch.hpp"

#include "../pml/lex.hpp"

using std::vector;

const char* lex_tag = "[lex]";

TEST_CASE("validate digitize(val)", lex_tag)
{
    vector<unsigned> digits;
    REQUIRE(digitize(0) == digits);
    digits = {1};
    REQUIRE(digitize(1) == digits);
    digits = {5};
    REQUIRE(digitize(5) == digits);
    digits = {1, 2, 3};
    REQUIRE(digitize(123) == digits);
    digits = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    REQUIRE(digitize(1234567890) == digits);
}

TEST_CASE("validate palindrome(val)", lex_tag)
{
    REQUIRE(palindrome(0) == true);
    REQUIRE(palindrome(1) == true);
    REQUIRE(palindrome(123) == false);
    REQUIRE(palindrome(121) == true);
    REQUIRE(palindrome(123454322) == false);
    REQUIRE(palindrome(123454321) == true);
}

TEST_CASE("validate permutation(val)", lex_tag)
{
    REQUIRE(permutation(0, 0) == true);
    REQUIRE(permutation(1, 1) == true);
    REQUIRE(permutation(1, 2) == false);
    REQUIRE(permutation(123, 321) == true);
    REQUIRE(permutation(122, 321) == false);
    REQUIRE(permutation(123456, 624351) == true);
    REQUIRE(permutation(123456, 624352) == false);
    REQUIRE(permutation(123456, 6243521) == false);
}
