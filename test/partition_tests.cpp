#include "catch.hpp"

#include "../pml/partition.hpp"

const char* part_tag = "[partition]";

TEST_CASE("validate partition(k)", part_tag)
{
    SECTION("validate partition calculation")
    { 
        REQUIRE(partition(0) == 1);
        REQUIRE(partition(1) == 1);
        REQUIRE(partition(2) == 2);
        REQUIRE(partition(3) == 3);
        REQUIRE(partition(4) == 5);
        REQUIRE(partition(5) == 7);
        REQUIRE(partition(100) == 190569292);
        REQUIRE(partition(MAX_PARTITION_K) == 17873792969689876004ull);
        REQUIRE(partition(MAX_PARTITION_K + 1) == 0);
        REQUIRE(partition(1000) == 0);
    }

    SECTION("validate partition helper function")
    {
        uint64_t* cache = new uint64_t[MAX_PARTITION_K]{0};
        for (uint64_t i = 0; i <= MAX_PARTITION_K; i++)
        {
            REQUIRE(partition(i) == partition(i, cache));
        }
        delete[] cache;
    }
}

TEST_CASE("validate general_pent(k)", part_tag)
{
    REQUIRE(general_pent(0) == 1);
    REQUIRE(general_pent(1) == 2);
    REQUIRE(general_pent(2) == 5);
    REQUIRE(general_pent(3) == 7);
    REQUIRE(general_pent(4) == 12);
    REQUIRE(general_pent(5) == 15);
    REQUIRE(general_pent(6) == 22);
    REQUIRE(general_pent(7) == 26);
}
