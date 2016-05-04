# totient
functions for working with Euler's totient function

# about

`totient.hpp` contains functions for evaluating Euler's totient
function.

`totient.hpp` depends on `primes.hpp` for generation of primes.

# primary functions

```C++
    vector<uint64_t> totient(uint64_t val);
    vector<uint64_t> totient(uint64_t val, vector<uint64_t> primes);
```

Evaluate the totient function for `val`. If `primes` is not provided,
it will be created using `primeSieve` from `primes.hpp`.

```C++
    vector<uint64_t> totient(uint64_t val, vector<uint64_t> factors);
```

Evaluate the totient of `val` with the prime factorization of `factors`.
This function is called by the other two, which computer the factorization
beforehand.

# extras

The string `PHI_SYMBOL` is defined as the unicode encoded character for the
phi symbol "φ". This symbol is used to represent the totient function, and
is provided for convenience of output.
