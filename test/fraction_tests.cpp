#include "catch.hpp"

#include "../pml/fraction.hpp"

const char* fraction_tag= "[fraction]";

TEST_CASE("validate prase_fraction(string)", fraction_tag)
{
    int64_t n, d;
    parse_fraction("1/2", n, d);
    REQUIRE(n == 1);
    REQUIRE(d == 2);
    parse_fraction("4/0/", n, d);
    REQUIRE(n == 4);
    REQUIRE(d == 0);
    parse_fraction("4", n, d);
    REQUIRE(n == 0);
    REQUIRE(d == 0);
}

TEST_CASE("validate reduce(n, d)", fraction_tag)
{
    int64_t n, d;
    
    n = 1; d = 2;
    reduce(n, d);
    REQUIRE(n == 1);
    REQUIRE(d == 2);

    n = 6; d = 2;
    reduce(n, d);
    REQUIRE(n == 3);
    REQUIRE(d == 1);
    
    n = 2; d = 4;
    reduce(n, d);
    REQUIRE(n == 1);
    REQUIRE(d == 2);

    n = 0; d = 0;
    reduce(n, d);
    REQUIRE(n == 0);
    REQUIRE(d == 0);

    n = 0; d = 2;
    reduce(n, d);
    REQUIRE(n == 0);
    REQUIRE(d == 2);

    n = 2; d = 0;
    reduce(n, d);
    REQUIRE(n == 2);
    REQUIRE(d == 0);

    n = 1; d = 2;
    REQUIRE(is_reduced(n, d) == true);

    n = 2; d = 2;
    REQUIRE(is_reduced(n, d) == false);
}

TEST_CASE("validate frac_comp()", fraction_tag)
{
    int64_t n1, n2, d1, d2;
    
    n1 = 1; d1 = 2;
    n2 = 2; d2 = 2;
    REQUIRE(frac_comp(n1, d1, n2, d2) == -1);

    n1 = 1; d1 = 2;
    n2 = 4; d2 = 8;
    REQUIRE(frac_comp(n1, d1, n2, d2) == 0);

    n1 = 3; d1 = 2;
    n2 = 1; d2 = 2;
    REQUIRE(frac_comp(n1, d1, n2, d2) == 1);
}

TEST_CASE("validate fraction arithmetic", fraction_tag)
{
    int64_t n1, d1, n2, d2;

    n1 = 1; d1 = 2;
    n2 = 2; d2 = 3;
    frac_add(n1, d1, n2, d2);
    REQUIRE(n1 == 7);
    REQUIRE(d1 == 6);
    
    n1 = 3; d1 = 4;
    n2 = 1; d2 = 2;
    frac_sub(n1, d1, n2, d2);
    REQUIRE(n1 == 1);
    REQUIRE(d1 == 4);

    n1 = 1; d1 = 1;
    n2 = 2; d2 = 2;
    frac_div(n1, d1, n2, d2);
    REQUIRE(n1 == 1);
    REQUIRE(d1 == 1);

    n1 = 1; d1 = 3;
    n2 = 2; d2 = 4;
    frac_mul(n1, d1, n2, d2);
    REQUIRE(n1 == 1);
    REQUIRE(d1 == 6);
}
