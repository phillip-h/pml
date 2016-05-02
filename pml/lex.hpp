#ifndef __PML_LEX__
#define __PML_LEX__

#include <algorithm>
#include <cstdint>
#include <vector>

inline std::vector<unsigned> digitize(uint64_t val)
{
    std::vector<unsigned> digits;
    
    while (val != 0)
    {
        digits.push_back(val % 10);
        val /= 10;
    }

    std::reverse(digits.begin(), digits.end());
    return digits;
}

inline bool palindrome(uint64_t val)
{
    std::vector<unsigned> digits = digitize(val);

    for (unsigned i = 0; i < digits.size() / 2; i++)
    {
        if (digits.at(i) != digits.at(digits.size() - i - 1))
            return false;
    }
    return true;
}

inline bool permutation(uint64_t a, uint64_t b)
{
    std::vector<unsigned> aVec = digitize(a);
    std::vector<unsigned> bVec = digitize(b);

    if (aVec.size() != bVec.size())
        return false;

    std::sort(aVec.begin(), aVec.end());
    std::sort(bVec.begin(), bVec.end());
    
    return aVec == bVec;
}

#endif
