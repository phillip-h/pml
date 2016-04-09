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

inline std::vector<uint64_t> rho(uint64_t val)
{
    std::vector<uint64_t> factors;
    
    if (val == 0)
        return factors;
 
    uint64_t fac;
    std::vector<uint64_t> tmp_factor;
    while (val != 1)
    {
        fac = rho_f(val);
        if (fac != 1) {
            if (fac < 1042 || fac == val) { 
                tmp_factor = factorize(fac);
            } else {
                tmp_factor = rho(fac);
            }
            factors.insert(factors.begin(), tmp_factor.begin(),
                                            tmp_factor.end());
            val /= fac;
        } else {
            break;
        }
    }

    return factors;
}

inline std::vector<uint64_t> quick_factorize(uint64_t val)
{
    std::vector<uint64_t> factors;
    if (val == 0)
        return factors;

    while ((val & 0x01) == 0)
    {
        val >>= 1;
        factors.push_back(2);
    }
    
    std::vector<uint64_t> other_factors = rho(val);
    factors.insert(factors.end(), other_factors.begin(), 
                                  other_factors.end());
    
    uint64_t mul = 1;
    for (uint64_t u : factors)
        mul *= u;

    if (mul != val) {
        other_factors = factorize(val / mul);
        factors.insert(factors.end(), other_factors.begin(), 
                                      other_factors.end());
    }

    std::sort(factors.begin(), factors.end());

    return factors;
}

#endif
