# complex
A simple complex number class

# about

`complex.hpp` contains a simple class to represent and operate on 
complex numbers. Operator overloads are provided so that the class
can be used in a more natural way.

Note -- this module is a work in progress, and is currently missing
several useful operations.

# constructors

```C++
    complex(double a = 0, double b = 0);
    complex(const complex& other);
```

The first constructor will create a complex number with real part `a`
and imaginary part `b`. The arguments default to zero.

The second constructor is a copy constructor, and will create a copy
of `other`.

# operations

```C++
    double abs() const;
```

Returns the absolute value of the complex number, ie, it's distance
from `(0, 0)`.

```C++
    complex conjugate() const;
```

Return a new complex number representing the complex conjugate. This
function does not modify the original complex number.

```C++
    complex scale(const double scale);
```

Preform scalar multiplication on the complex number. This function returns
the complex number itself, not a copy, so that operations can be chained.

```C++
    complex& operator=(const complex& rhs);
```

Overloaded `=` operator, simply calls the copy constructor.

```C++
    complex& operator+=(const complex& rhs);
    const complex operator+(const complex& rhs) const;
```

Addition operators.

```C++
    complex& operator-=(const complex& rhs);
    const complex operator-(const complex& rhs) const;
```

Subtraction operators.

```C++
    complex& operator*=(const complex& rhs);
    const complex operator*(const complex& rhs) const;
```

Complex multiplication operators.

```C++
    bool operator==(const complex& rhs) const;
    bool operator!=(const complex& rhs) const;
```

Equality operators.

# utility

```C++
    string to_str() const;
```

Return a string of the complex number in form `a + bi`.

```C++
    const string I_SYMBOL = "\u03B9";
```

A Unicode constant of the Greek lowercase iota `ι`, which can be used as
a nice way of distinguishing the imaginary constant from a normal 'i'.
