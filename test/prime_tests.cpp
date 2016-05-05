#include "catch.hpp"

#include "../pml/prime.hpp"

using std::vector;

const char* prime_tag = "[prime]";

TEST_CASE("validate prime_sieve()", prime_tag)
{
    vector<uint64_t> primes = prime_sieve(0);
    REQUIRE(primes.size() == 0);
    
    primes = prime_sieve(10);
    REQUIRE(primes.size() == 4);
    
    primes = prime_sieve(100);
    REQUIRE(primes.size() == 25);
    
    primes = prime_sieve(1000000);
    REQUIRE(primes.size() == 78498);
}

TEST_CASE("validate atkin() equals eratosthenes()", prime_tag)
{
    REQUIRE(atkin(0) == eratosthenes(0));
    REQUIRE(atkin(10) == eratosthenes(10));
    REQUIRE(atkin(100) == eratosthenes(100));
    REQUIRE(atkin(1000000) == eratosthenes(1000000));
}

TEST_CASE("validate is_primes()", prime_tag)
{
    REQUIRE(is_prime(0) == false);
    REQUIRE(is_prime(1) == false);
    REQUIRE(is_prime(2) == true);
    REQUIRE(is_prime(10) == false);
    REQUIRE(is_prime(97) == true);
}

TEST_CASE("validated factorize()", prime_tag)
{
    vector<uint64_t> fac;

    REQUIRE(factorize(0) == fac);
    REQUIRE(factorize(1) == fac);

    fac = {2, 2, 5};
    REQUIRE(factorize(20) == fac);

    fac = {2, 2, 5, 5};
    REQUIRE(factorize(100) == fac);

    fac = {17};
    REQUIRE(factorize(17) == fac);
}
