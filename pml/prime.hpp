#ifndef __PML_PRIME__
#define __PML_PRIME__

#include <algorithm>
#include <cstdint>
#include <vector>

inline std::vector<uint64_t> atkin(uint64_t max)
{
    std::vector<uint64_t> primes;
    
    if (max <= 2)
        primes.push_back(2);
    if (max <= 3)
        primes.push_back(3);
    if (max <= 5)
        primes.push_back(5);
    if (max < 6)
        return primes;

    std::vector<bool> sieve(max + 1);
    std::fill(sieve.begin(), sieve.end(), true);

    uint64_t mod;
    for (uint64_t val = 6; val <= max; val++)
    {
        mod = val % 60;   
    }
}

inline std::vector<uint64_t> eratosthenes(uint64_t max)
{
    if (max == 0)
        return std::vector<uint64_t>();
    std::vector<bool> sieve(max + 1);
    std::fill(sieve.begin(), sieve.end(), true);
    sieve[0] = false; 

    std::vector<uint64_t> primes;

    uint64_t val = 2;
    while(val <= max)
    {
        if (sieve.at(val) != false) {
            primes.push_back(val);
            for (uint64_t i = val; i < max + 1; i += val)  
                sieve[i] = false;
        }
        val++;
    }

    return primes;
}

inline std::vector<uint64_t> prime_sieve(uint64_t max)
{
   return eratosthenes(max); 
}

inline std::vector<uint64_t> factorize(uint64_t val, 
                                       std::vector<uint64_t> primes)
{
    if (val <= 1)
        return std::vector<uint64_t>();

    std::vector<uint64_t> fac; 

    for (unsigned i = 0; i < primes.size(); i++)
    {
        if (primes.at(i) > val)
            break;
        while (val % primes.at(i) == 0)
        {
            fac.push_back(primes.at(i));
            val /= primes.at(i);
        }
    }

    return fac;
}

inline std::vector<uint64_t> factorize(uint64_t val)
{
    return factorize(val, prime_sieve(val));
}

inline bool is_prime(uint64_t val)
{
    std::vector<uint64_t> primes = prime_sieve(val);
    return primes.size() != 0 && primes.at(primes.size() - 1) == val;
}

#endif
