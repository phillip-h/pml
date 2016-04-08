# factor
functions for integer factorization and other related operations

# about

`factor.hpp` contains functions for rapid integer factorization and
other functions such as finding the greatest common divisor and least
common multiple of a number.

`factor.hpp` depends on `prime.hpp` for `prime_sieve` and fallback
factorization.

# functions

## primary functions

These are the functions you will probably want to use.

```C++
    uint64_t gdc(uint64_t a, uint64_t b);
    uint64_t lcm(uint64_t a, uint64_t b);
```

Find the greatest common divisor and the least common multiple of `a` and
`b` respectivly. `lcm()` calls `gdc()` as part of it's operation.

```C++
    vector<uint64_t> quick_factorize(uint64_t val);
```

Quickly factorize `val` and return a vector of it's prime factors. This
function uses Pollard's rho algorithm for most of it's work, and uses
`factorize()` from `prime.hpp` as a fallback.

In total, the function first seperates out any twos from `val` using
bitwise operations. Then, Pollard's rho algorith is used to attempt 
factorization. If `val` is not one after application of the algorithm,
`factorize()` is used to generate the remaining factors.


## secondary functions

These are used by the primary functions and are probably not of much
interest to the average user.

```C++
   uint64_t rho_f(uint64_t val); 
   vector<uint64_t> rho(uint64_t val); 
```

Worker functions for Pollard's rho algorithm. The first function finds a
factor of `val` and returns it, while the second keeps track of all factors
found, as well as ensuring the factors returned by the first function are
fully reduced. These functions are not gauranteed to return the whole
factorization of `val`! Use `quick_factorize()` unless you REALLY need
the rho algorithm.