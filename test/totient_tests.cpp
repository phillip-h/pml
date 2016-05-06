#include "catch.hpp"

#include "../pml/totient.hpp"

const char* totient_tag = "[totient]";

TEST_CASE("validate totient(n)", totient_tag)
{
    REQUIRE(totient(0) == 1);
    REQUIRE(totient(1) == 1);
    REQUIRE(totient(2) == 1);
    REQUIRE(totient(3) == 2);
    REQUIRE(totient(4) == 2);
    REQUIRE(totient(5) == 4);
    REQUIRE(totient(6) == 2);
    REQUIRE(totient(7) == 6);
    REQUIRE(totient(8) == 4);
    REQUIRE(totient(9) == 6);
    REQUIRE(totient(99) == 60);
}

TEST_CASE("validate totient_r(n)", totient_tag)
{
    REQUIRE(totient_r(0) == totient(0));
    REQUIRE(totient_r(1) == totient(1));
    REQUIRE(totient_r(2) == totient(2));
    REQUIRE(totient_r(3) == totient(3));
    REQUIRE(totient_r(4) == totient(4));
    REQUIRE(totient_r(5) == totient(5));
    REQUIRE(totient_r(6) == totient(6));
    REQUIRE(totient_r(7) == totient(7));
    REQUIRE(totient_r(8) == totient(8));
    REQUIRE(totient_r(9) == totient(9));
    REQUIRE(totient_r(99) == totient(99));
}
