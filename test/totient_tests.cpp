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
