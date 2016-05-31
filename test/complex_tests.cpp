#include "catch.hpp"

#include "../pml/complex.hpp"

const char* complex_tag = "[complex]";

TEST_CASE("validate complex", complex_tag)
{
    complex a(1, 2);

    REQUIRE(a.a == 1);
    REQUIRE(a.b == 2);

    complex b(2, 1);

    REQUIRE(a == a);
    REQUIRE(a != b);
    
    b = a;
    REQUIRE(a == b);

    b = complex(a);
    REQUIRE(a == b);

    complex c;
    REQUIRE(c.a == 0);
    REQUIRE(c.b == 0);

    b = complex(2, 1);
    a = a + b;
    REQUIRE(a.a == 3);
    REQUIRE(a.b == 3);

    a = complex(1, 2);
    b = complex(2, 1);
    a *= b;
    REQUIRE(a.a == 0);
    REQUIRE(a.b == 5);

    a = a - a;
    REQUIRE(a == c);

    a = complex(1, 1);
    REQUIRE(a.abs() == sqrt(2));

    a.scale(2);
    REQUIRE(a.a == 2);
    REQUIRE(a.b == 2);
    REQUIRE(a.abs() == sqrt(8));

    a = complex(1, 2);
    a = a.conjugate();
    REQUIRE(a.a == 1);
    REQUIRE(a.b == -2);

    a = complex(3, 4);
    a = a;
    REQUIRE(a.a == 3);
    REQUIRE(a.b == 4);
}
