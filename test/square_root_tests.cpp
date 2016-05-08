#include "catch.hpp"

#include "../pml/square_root.hpp"

using std::vector;

const char* sr_tag = "[lex]";

TEST_CASE("validate root_fraction()", sr_tag)
{
    REQUIRE(root_fraction(0).size() == 0); 
    REQUIRE(root_fraction(1).size() == 0); 
    REQUIRE(root_fraction(2).size() == 2); 
    REQUIRE(root_fraction(9).size() == 0); 
    
    vector<uint64_t> frac = {1, 2};
    REQUIRE(root_fraction(2) == frac);

    frac = {2, 1, 1, 1, 4};
    REQUIRE(root_fraction(7) == frac);

    frac = {10, 1, 2, 10, 2, 1, 20};
    REQUIRE(root_fraction(114) == frac);
}

TEST_CASE("validate expand_root()", sr_tag)
{
    REQUIRE(expand_root(2, 1) == 1.5);
    REQUIRE(expand_root(2, 2) == 1.4);

    REQUIRE(expand_root(0, 1) == 0);
    REQUIRE(expand_root(1, 1) == 0);
    REQUIRE(expand_root(4, 1) == 0);
}
