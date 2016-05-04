#ifndef __PML_TOTIENT__
#define __PML_TOTIENT__

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include "factor.hpp"
#include "prime.hpp"

const std::string PHI_SYMBOL = "\u03C6";

inline uint64_t totient(uint64_t val, 
                        const std::vector<uint64_t> &primes)
{
    if (val <= 2)
        return 1;

    if (std::find(primes.begin(), primes.end(), val) != primes.end())
        return val - 1;

    uint64_t totient = val;

    while ((val & 0x01) == 0)
    {
        totient *= (1 - (1.0 / 2.0));
        val >>= 1;
    }

    for (unsigned i = 0; i < primes.size(); i++)
    {
        if (primes.at(i) > val)
            break;

        if (val % primes.at(i) == 0) {
            totient *= (1 - (1.0 / primes.at(i)));
            do 
            {
                val /= primes.at(i);
            } while (val % primes.at(i) == 0);
        }
    }

    return totient;
}

inline uint64_t totient(uint64_t val)
{
    return totient(val, prime_sieve(val));
}

#endif
