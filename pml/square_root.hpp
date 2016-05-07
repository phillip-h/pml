#ifndef __PML_SQUARE_ROOT
#define __PML_SQUARE_ROOT

#include <cmath>
#include <string>
#include <vector>

const std::string SQUARE_ROOT_SYMBOL = "\u221A"; 
const uint64_t DEF_EXPANSION_ITERATIONS = 2;

inline std::vector<uint64_t> root_fraction(uint64_t val)
{
    uint64_t m = 0;
    uint64_t d = 1;
    double a0 = sqrt(val); 
    uint64_t a = floor(a0);
    if (a == a0)
        return std::vector<uint64_t>();
    
    std::vector<uint64_t> expansion {a};

    uint64_t end = a * 2;
    while (a != end){
        m = d * a - m;
        d = (val - m * m) / d;
        a = floor((a0 + m) / d); 
        expansion.push_back(a);
    }

    return expansion;
}

inline void expand_root(uint64_t &num, uint64_t &den,
                        std::vector<uint64_t> fraction, 
                        uint64_t iterations)
{
    if (!fraction.size()) {
        num = 0;
        den = 0;
    }

    for (unsigned i = 1; i < iterations; i++)
        fraction.insert(fraction.end(), 
                        fraction.begin() + 1, fraction.end());
    num = 1;
    den = fraction.at(fraction.size() - 1);
    for (auto it = fraction.rbegin() + 1; it != fraction.rend() - 1; it++)
    {
        num = (*it) * den + num;
        std::swap(num, den);
    }
    num += fraction.at(0) * den;
}

inline void expand_root(uint64_t &num, uint64_t &den,
                          std::vector<uint64_t> fraction)
{
   expand_root(num, den, fraction, DEF_EXPANSION_ITERATIONS);
}

inline void expand_root(uint64_t &num, uint64_t &den,
                          uint64_t val, uint64_t iterations)
{
    expand_root(num, den, root_fraction(val), iterations);
}

inline void expand_root(uint64_t &num, uint64_t &den, uint64_t val)
{
    expand_root(num, den, root_fraction(val), 
                          DEF_EXPANSION_ITERATIONS);
}

inline double expand_root(std::vector<uint64_t> fraction, 
                          uint64_t iterations)
{
    if (!fraction.size())
        return 0;

    uint64_t num = 0;
    uint64_t den = 0;
    expand_root(num, den, fraction, iterations);

    return (double) num / den;
}

inline double expand_root(std::vector<uint64_t> fraction)
{
    return expand_root(fraction, DEF_EXPANSION_ITERATIONS);
}

inline double expand_root(uint64_t val, uint64_t iterations)
{
    return expand_root(root_fraction(val), iterations);
}

inline double expand_root(uint64_t val)
{
    return expand_root(root_fraction(val), DEF_EXPANSION_ITERATIONS);
}

inline long double expand_root_float(std::vector<uint64_t> fraction, 
                               uint64_t iterations)
{
    if (!fraction.size()) {
        return 0.0;
    }

    for (unsigned i = 1; i < iterations; i++)
        fraction.insert(fraction.end(), 
                        fraction.begin() + 1, fraction.end());
    long double num = 1.0;
    long double den = fraction.at(fraction.size() - 1);
    for (auto it = fraction.rbegin() + 1; it != fraction.rend() - 1; it++)
    {
        num = (*it) * den + num;
        std::swap(num, den);
    }
    num += fraction.at(0) * den;

    return num / den;
}

inline long double expand_root_float(std::vector<uint64_t> fraction)
{
    return expand_root_float(fraction, DEF_EXPANSION_ITERATIONS);
}

inline long double expand_root_float(uint64_t val, uint64_t iterations)
{
    return expand_root_float(root_fraction(val), iterations);
}

inline long double expand_root_float(uint64_t val)
{
    return expand_root_float(root_fraction(val), DEF_EXPANSION_ITERATIONS);
}

#endif
