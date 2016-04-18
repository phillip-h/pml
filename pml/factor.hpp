#ifndef __PML_FACTOR__
#define __PML_FACTOR__

#include <vector>

#include "prime.hpp"

inline uint64_t gdc(uint64_t a, uint64_t b)
{
    if (a < b)
        return gdc(b, a);

    uint64_t mod;
    while (b != 0)
    {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

inline uint64_t lcm(uint64_t a, uint64_t b)
{
    if (a == 0 && b == 0)
        return 0;

    uint64_t num = a * b;
    return num / gdc(a, b);
}

inline uint64_t rho_f(uint64_t val)
{
    if (val == 0)
        return 1;

    uint64_t x_fixed = 2;
    uint64_t x = 2;
    uint64_t cycles = 2;
    uint64_t factor = 1;

    while (factor == 1)
    {
        for (unsigned i = 0; i < cycles && factor <= 1; i++)
        {
            x = (x * x + 1) % val;    
            factor = gdc(x - x_fixed, val);
        }

        cycles *= 2;
        x_fixed = x;
    }

    return factor;
}

const uint64_t MIN_RHO_FACTOR = pow(2, 20);

inline std::vector<uint64_t> quick_factorize(uint64_t val,
                                             std::vector<uint64_t> &fac,
                                       const std::vector<uint64_t> &primes,
                                             bool recurse = false);

inline std::vector<uint64_t> rho(uint64_t val, 
                           const std::vector<uint64_t> &primes)
{
    std::vector<uint64_t> factors;
    
    if (val == 0)
        return factors;
 
    uint64_t fac;
    while (val != 1)
    {
        fac = rho_f(val);
        if (fac != 1) {
            quick_factorize(fac, factors, primes, true);
            val /= fac;
        } else {
            break;
        }
    }

    return factors;
}

inline std::vector<uint64_t> quick_factorize(uint64_t val,
                                             std::vector<uint64_t> &factors,
                                       const std::vector<uint64_t> &primes,
                                             bool recurse)
{
    if (val == 0)
        return factors;

    while ((val & 0x01) == 0)
    {
        val >>= 1;
        factors.push_back(2);
    }

    if (val <= MIN_RHO_FACTOR) {
        std::vector<uint64_t> other_factors = factorize(val, primes);
        factors.insert(factors.end(), other_factors.begin(), 
                                      other_factors.end());
        return factors;
    }

    if (recurse) {
        if (primes.at(primes.size() - 1) < val) {
            std::vector<uint64_t> other_factors = factorize(val);
            factors.insert(factors.end(), other_factors.begin(), 
                                          other_factors.end());
        } else {
            std::vector<uint64_t> other_factors = factorize(val, primes);
            factors.insert(factors.end(), other_factors.begin(), 
                                          other_factors.end());
        }
        return factors;
    }

    std::vector<uint64_t> other_factors = rho(val, primes);
    factors.insert(factors.end(), other_factors.begin(), 
                                  other_factors.end());

    return factors;
}

inline std::vector<uint64_t> quick_factorize(uint64_t val,
                                       const std::vector<uint64_t> &primes)
{
    std::vector<uint64_t> factors;
    quick_factorize(val, factors, primes);
    return factors;
}

inline std::vector<uint64_t> quick_factorize(uint64_t val)
{
    const std::vector<uint64_t> primes = prime_sieve(val);
    return quick_factorize(val, primes);
}
#endif
