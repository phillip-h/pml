#include "catch.hpp"

#include "../pml/num_util.hpp"

const char* util_tag= "[util]";

TEST_CASE("validate is_perfect_square()", util_tag)
{
    auto lambda = [](uint64_t val)
    {
        double root = sqrt(val);
        return root == (int) root;
    };

    for (unsigned i = 0; i <= 100000; i++)
        REQUIRE(is_perfect_square(i) == lambda(i));
}
