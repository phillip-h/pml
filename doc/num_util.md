# num_util

numeric utility functions

# about

`num_util.hpp` contains various utility functions that do not
fit well anywhere else.

# functions

```C++
    bool is_perfect_square(uint64_t val)
```

Returns `true` if `val` is a perfect square, and `false` if it
is not. This function uses some tricks to be much faster than a
typical naïve square-checking function, i.e., taking the square root
and then checking if the double value is equal to the value cast to
and integer.
