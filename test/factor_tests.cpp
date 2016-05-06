#include "catch.hpp"

#include "../pml/factor.hpp"

using std::vector;

const char* factor_tag = "[factor]";

TEST_CASE("validate gcd()", factor_tag)
{
    REQUIRE(gcd(2, 1) == gcd(1, 2));
    REQUIRE(gcd(0, 0) == 0);
    REQUIRE(gcd(0, 10) == 10);
    REQUIRE(gcd(8, 12) == 4);
}

TEST_CASE("validate gcd_r()", factor_tag)
{
    REQUIRE(gcd_r(0, 10) == 10);
    REQUIRE(gcd_r(20, 13) == gcd_r(13, 20));
    REQUIRE(gcd_r(161362, 514214) == gcd(161362, 514214));
}

TEST_CASE("validate lcm()", factor_tag)
{
    REQUIRE(lcm(0, 4) == 0);
    REQUIRE(lcm(13, 54) == lcm(54, 13));
    REQUIRE(lcm(5, 2) == 10);
}

TEST_CASE("validate quick_factorize()", factor_tag)
{
    REQUIRE(quick_factorize(0) == factorize(0));
    REQUIRE(quick_factorize(1) == factorize(1));
    REQUIRE(quick_factorize(5) == factorize(5));
    REQUIRE(quick_factorize(10) == factorize(10));
    REQUIRE(quick_factorize(170) == factorize(170));
    REQUIRE(quick_factorize(5235) == factorize(5235));
}
