# lex
functions for checking lexographic properties of numbers

# about

`lex.hpp` contains methods for working with the *digits* of numbers,
rather than the numbers themselves.

# primary functions

```C++
   vector<unsigned> digitize(uint64_t val); 
```

Return a vector of each of the digits of `val`, called by most
functions in this header.

```C++
    bool palindrome(uint64_t val);
```

Return `true` if `val` is a palindrome and `false` if it is not.

```C++
    bool permutation(uint64_t a, uint64_t b);
```

Return `true` if `a` and `b` are permutations of each other, that is,
that they are composed of the same digits but in a different order.
