# fraction
functions for working with fractions

# about

`fraction.hpp` contains functions for parsing, comparing, and preforming
arithmetic operations on fractions as represented by a numerator and 
a denominator. 

note--unlike most of the content in this library, `fraction.hpp` works
with signed integers of type `int64_t`.

## primary functions

These are the functions you will probably want to use.

```C++
    void reduce(int64_t &numerator, int64_t &denominator);
```

Reduce the fraction until GDC(numerator, denominator) equals one.

```C++
    bool is_reduced(int64_t numerator, int64_t denominator);
```

Returns `true` if the fraction is fully reduced, and `false` if it
is not.

```C++
    void fractionize(double dec, int64_t &numerator, int64_t &denominator);
```

Convert the value `dec` into a reduced fraction.

note--this function is unable to parse repeating decimals! `1.3333` will
return `13333/10000`, not `4/3`!

```C++
    int frac_comp(int64_t numa, int64_t dena,
                  int64_t numb, int64_t denb);
```

Compare the two fractions and return `-1` if fraction A is less than
fraction B, `1` if fraction A is greater than fraction B, and `0` if they
are exactly equal.

```C++
    void frac_add(int64_t numa, int64_t dena,
                  int64_t numb, int64_t denb,
                  int64_t &numr, int64_t &denr);
    void frac_add(int64_t &numa, int64_t &dena,
                  int64_t numb, int64_t denb);

    void frac_sub(int64_t numa, int64_t dena,
                  int64_t numb, int64_t denb,
                  int64_t &numr, int64_t &denr);
    void frac_sub(int64_t &numa, int64_t &dena,
                  int64_t numb, int64_t denb);

    void frac_mul(int64_t numa, int64_t dena,
                  int64_t numb, int64_t denb,
                  int64_t &numr, int64_t &denr);
    void frac_mul(int64_t &numa, int64_t &dena,
                  int64_t numb, int64_t denb);

    void frac_div(int64_t numa, int64_t dena,
                  int64_t numb, int64_t denb,
                  int64_t &numr, int64_t &denr);
    void frac_div(int64_t &numa, int64_t &dena,
                  int64_t numb, int64_t denb);

```

Fraction arithmetic operations. Store the result in `numr` and `denr` if
provided, or fraction A if they are not.

## secondary functions

These are used by the primary functions and are probably not of much
interest to the average user.

```C++
    void common_denominator(int64_t &numa, int64_t &dena,
                            int64_t &numb, int64_t &denb);
```

Manipulate fraction A and fraction B to have a common denominator. 
This function does not ensure the lowest common denominator is found,
and as such is not recomended for general use. It is still used
by several other functions in the header.
