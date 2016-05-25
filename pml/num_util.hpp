#ifndef __PML_NUM_UTIL__
#define __PML_NUM_UTIL__

#include <cmath>
#include <cstdint>

inline bool is_perfect_square(uint64_t val)
{
    const uint8_t first_nibble = val & 0xf;

    if (first_nibble > 9)
        return false;

    if (first_nibble != 2 && first_nibble != 3 && 
        first_nibble != 5 && first_nibble != 6 &&
        first_nibble != 7 && first_nibble != 8) {
        double root = sqrt(val);
        return root == (int) root;
    }

    return false;
}

#endif
