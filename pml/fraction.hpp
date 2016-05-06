#ifndef __PML_FRACTION__
#define __PML_FRACTION__

#include <cmath>
#include <cstdlib>
#include <string>

#include "factor.hpp"

inline void parse_fraction(std::string frac, int64_t &num,
                                             int64_t &den)
{
    unsigned pos = 0;
    for (unsigned i = 1; i < frac.size(); i++)
    {
        if (frac.at(i) == '/') {
            pos = i;
            break;
        }
    }

    if (pos == 0) {
        num = 0;
        den = 0;
        return;
    }

    num = std::stoll(frac.substr(0, pos));
    den = std::stoll(frac.substr(pos + 1, frac.size() - 1));
}

inline void reduce(int64_t &num, int64_t &den)
{
    if (num == 0 || den == 0)
        return;

    uint64_t numv = num >= 0 ? num : -1 * num;
    uint64_t denv = den >= 0 ? den : -1 * den;

    uint64_t div;
    while ((div = gcd(numv, denv)) != 1) 
    {
        numv /= div;
        denv /= div;
    }

    num = numv * (num >= 0 ? 1 : -1);
    den = denv * (den >= 0 ? 1 : -1);
}

inline bool is_reduced(int64_t num, int64_t den)
{
    num = abs(num);
    den = abs(den);
    return gcd(num, den) == 1;
}

inline void fractionize(double dec, int64_t &num, int64_t &den)
{
    if (dec == 0) {
        num = 0;
        den = 1;
        return;
    }

    den = 1; 
    double int_;
    while (modf(dec * den, &int_) != 0)
    {
        den *= 10;
    }
    num = dec * den;

    reduce(num, den);
}

inline void common_denominator(int64_t &numa, int64_t &dena,
                               int64_t &numb, int64_t &denb)
{
    if (dena == denb)
        return;

    int64_t tmp = dena;
    numa *= denb;
    numb *= dena;
    dena *= denb;
    denb *= tmp;
}

inline int frac_comp(int64_t numa, int64_t dena,
                     int64_t numb, int64_t denb)
{
    if (numa == numb && dena == denb)
        return 0;

    common_denominator(numa, dena, numb, denb);

    if (numa == numb)
        return 0;
    return numa > numb ? 1 : -1;
}

inline void frac_add(int64_t numa, int64_t dena, 
                     int64_t numb, int64_t denb,
                     int64_t &numr, int64_t &denr)
{
    common_denominator(numa, dena, numb, denb); 
    numa += numb;
    numr = numa;
    denr = dena;
    reduce(numr, denr);
}

inline void frac_add(int64_t &numa, int64_t &dena,
                     int64_t numb, int64_t denb)
{
    return frac_add(numa, dena, numb, denb, numa, dena);
}

inline void frac_sub(int64_t numa, int64_t dena, 
                     int64_t numb, int64_t denb,
                     int64_t &numr, int64_t &denr)
{
    common_denominator(numa, dena, numb, denb); 
    numa -= numb;
    numr = numa;
    denr = dena;
    reduce(numr, denr);
}

inline void frac_sub(int64_t &numa, int64_t &dena,
                     int64_t numb, int64_t denb)
{
    return frac_sub(numa, dena, numb, denb, numa, dena);
}

inline void frac_mul(int64_t numa, int64_t dena, 
                     int64_t numb, int64_t denb,
                     int64_t &numr, int64_t &denr)
{
    numa *= numb;
    dena *= denb;
    numr = numa;
    denr = dena;
    reduce(numr, denr);
}

inline void frac_mul(int64_t &numa, int64_t &dena,
                     int64_t numb, int64_t denb)
{
    return frac_mul(numa, dena, numb, denb, numa, dena);
}

inline void frac_div(int64_t numa, int64_t dena, 
                     int64_t numb, int64_t denb,
                     int64_t &numr, int64_t &denr)
{
    frac_mul(numa, dena, denb, numb, numr, denr);
}

inline void frac_div(int64_t &numa, int64_t &dena,
                     int64_t numb, int64_t denb)
{
    return frac_div(numa, dena, numb, denb, numa, dena);
}

#endif
