# prime
functions for working with prime numbers

# about

`prime.hpp` contains functions for generating prime numbers, testing 
numbers for primality, and factoring numbers.

# functions

## primary functions
   
These are the functions you will probably want to use.

```C++
    vector<uint64_t> primeSieve(uint64_t max);  
```

Return a vector of the primes in [1, max]

```C++
    vector<uint64_t> factorize(uint64_t val);
    vector<uint64_t> factorize(uint64_t val, vector<uint64_t> primes);
```

Return a vector containing the prime factorization of `val`. If a
vector of primes is not provided, it will be created with `primeSieve()`.

```C++
    bool isPrime(uint64_t val);
```

Return `true` if `val` is a prime number and `false` if it is composite.
Note--this function ALWAYS generates a vector of primes to check agaisnt,
if you want to check agaisnt an existing vector, using a standard method
like `std::count` or `std::find`.


## secondary functions

These are used by the primary functions and are probably not of much
interest to the average user.

```C++
    vector<uint64_t> eratosthenes(uint64_t max);
    vector<uint64_t> atkin(uint64_t max);
```

The Sieve of Erathosthenes and the Sieve of Atkin, respectivly. The sieve
of Atkin is currently unfinished, and as such `primeSieve()` currently
relies on the Sieve of Erathosthenes.
