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

inline uint64_t totient_r(uint64_t val, 
                    const std::vector<uint64_t> &primes)
{
    if (val < 2)
        return 1;

    if (std::find(primes.begin(), 
                  primes.end(), val) != primes.end())
        return val - 1;

    if ((val & 0x01) == 0) {
        uint64_t rem = val >> 1;
        if ((rem & 0x01) == 0)
            return totient_r(rem, primes) << 1;
        else 
            return totient_r(rem, primes);
    }

    uint64_t rem;
    uint64_t oth;
    for (unsigned i = 0; i < primes.size(); i++)
    {
        if (primes.at(i) > val)
            break;
        if (val % primes.at(i) != 0)
            continue;

        rem = val / primes.at(i);
        oth = gcd_r(primes.at(i), rem);
        if (oth == 1) {
            return totient_r(primes.at(i), primes)
                 * totient_r(rem, primes);
        } else {
            return totient_r(primes.at(i), primes)
                 * totient_r(rem, primes)
                 / totient_r(oth, primes) * oth;
        }
    }

    return 0;
}

inline uint64_t totient_r(uint64_t val)
{
    return totient_r(val, prime_sieve(val));
}

#endif
