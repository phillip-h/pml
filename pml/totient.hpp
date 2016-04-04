#ifndef __PML_TOTIENT__
#define __PML_TOTIENT__

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include "prime.hpp"

const std::string PHI_SYMBOL = "\u03C6";

inline uint64_t totient_f(uint64_t val, std::vector<uint64_t> factors)
{
    factors.erase(std::unique(factors.begin(), factors.end()),
                  factors.end());

    unsigned totient = val;
    for (unsigned i = 0; i < factors.size(); i++)
    {
       totient *= (1 - (1.0 / factors.at(i)));  
    }
    return totient;
}

inline uint64_t totient(uint64_t val, std::vector<uint64_t> primes)
{
    return totient_f(val, factorize(val, primes));
}

inline uint64_t totient(uint64_t val)
{
    return totient(val, prime_sieve(val));
}

#endif
