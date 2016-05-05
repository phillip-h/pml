#include "catch.hpp"

#include "../pml/factor.hpp"

using std::vector;

const char* factor_tag = "[factor]";

TEST_CASE("validate gdc()", factor_tag)
{
    REQUIRE(gdc(2, 1) == gdc(1, 2));
    REQUIRE(gdc(0, 0) == 0);
    REQUIRE(gdc(0, 10) == 10);
    REQUIRE(gdc(8, 12) == 4);
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
