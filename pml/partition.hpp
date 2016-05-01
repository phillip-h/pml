#ifndef __PML_PARTITION__
#define __PML_PARTITION__

#include <cstdint>

const int64_t MAX_PARTITION_K = 416;

inline uint64_t general_pent(int64_t k)
{
    k += 2;
    if ((k & 0x01) == 1)
       k *= -1;
    k /= 2;
    return (3 * k - 1) * k / 2;
}

inline uint64_t partition(int64_t k, uint64_t* cache)
{
    if (k == 0)
        return 1;
    else if (k < 0 || k > MAX_PARTITION_K)
        return 0;
    else if (cache[k] != 0)
        return cache[k];

    uint64_t sum = 0;
    uint64_t sub = 0;
    int8_t neg = 0;
    uint64_t pent_ = general_pent(sub);
    while (pent_ <= (uint64_t) k)
    {
       sum += partition(k - pent_, cache) * (neg < 2 ? 1 : -1); 
       sub++;
       neg++;
       if (neg == 4)
           neg = 0;
       pent_ = general_pent(sub);
    }

    cache[k] = sum;
    return sum;
}

inline uint64_t partition(int k)
{
    uint64_t* cache = new uint64_t[k + 1]{0};
    uint64_t ret = partition(k, cache);
    delete[] cache;
    return ret;
}

#endif
