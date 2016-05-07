# square root
functions for working with square roots

# about

`square_root.hpp` contains functions for working with square roots.
At the moment this is limited to calculating and expanding continued
fractions.

# functions

```C++
    vector<uint64_t> root_fraction(uint64_t val);
```

Compute the continued fraction form of `val`. The first value
in the vector is the constant part, the rest of the vector is the
repeating part.

```C++
   void expand_root(uint64_t &num, uint64_t &den, 
                    vector<uint64_t> fraction);
   void expand_root(uint64_t &num, uint64_t &den, 
                    vector<uint64_t> fraction, uint64_t iterations);
   void expand_root(uint64_t &num, uint64_t &den, 
                    uint64_t val);
   void expand_root(uint64_t &num, uint64_t &den, 
                    uint64_t val, uint64_t iterations);
```

Expand the fraction into `num` and `den`. If a continued fraction is not
provided, it is generated from `val. If `iterations` is not provided,
it is set to a default value. Note that a high value of `iterations`
risks overflow errors, especially with roots with a longer period.

```C++
   long double expand_root(vector<uint64_t> fraction);
   long double expand_root(vector<uint64_t> fraction, uint64_t iterations);
   long double expand_root(uint64_t val);
   long double expand_root(uint64_t val, uint64_t iterations);
```

Expand the fraction using the previous set of methods, then divide
and store the result in a double.

```C++
   long double expand_root_float(vector<uint64_t> fraction);
   long double expand_root_float(vector<uint64_t> fraction, 
                                 uint64_t iterations);
   long double expand_root_float(uint64_t val);
   long double expand_root_float(uint64_t val, uint64_t iterations);
```

Same as the above, but use a `long double` to represent the
numerator and denominator during the calculation instead of a `uint64_t`.

# extras

```C++
const string SQUARE_ROOT_SYMBOL
```

A constant string of the unicode square root symbol.
