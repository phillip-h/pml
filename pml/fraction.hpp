#ifndef __PML_FRACTION__
#define __PML_FRACTION__

#include <cmath>

#include "factor.hpp"

inline void reduce(int64_t &num, int64_t &den)
{
    uint64_t numv = num >= 0 ? num : -1 * num;
    uint64_t denv = den >= 0 ? den : -1 * den;

    uint64_t div;
    while ((div = gdc(numv, denv)) != 1) 
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
    return gdc(num, den) == 1;
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

inline int frac_comp(int64_t numa, int64_t dena, int64_t numb, int64_t denb)
{
    if (numa == numb && dena == denb)
        return 0;

    common_denominator(numa, dena, numb, denb);
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
