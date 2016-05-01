# partition
functions for computing the partition function

# about

`partition.hpp` contains functions for calculating the partition
function `p()` of numbers.

Note that because the partition function grows extremely quickly,
this module can only handle values less than or equal to `416`. 
Attempting to calculate a value greater than this will result in
`0` being returned.

# functions

## primary functions
   
These are the functions you will probably want to use.

```C++
    uint64_t partition(int64_t k);  
    uint64_t partition(int64_t k, uint64_t* cache);  
```

Calculate the partition of `k`. A cache is utilised to prevent the
computation from taking an extremely long time. The only difference
between the first and second functions is that the first one will
create and destroy the cache within the function body. If you are going
to be computing numerous partitions, it would be advisable to manually
create a cache for use with the second function, so that results can be
kept between partition calculation.

Note--these functions are recursive in nature. However, the number of 
stack frames present at any time should remain relatively small, and 
because of the small limit on `k`, stack overflows should not occur.

## secondary functions

These are used by the primary functions and are probably not of much
interest to the average user.

```C++
   uint64_t general_pent(int64_t k); 
```

Return the kth generalized pentagonal number.

