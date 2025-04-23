//
// Created by eden on 4/21/25.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"

using namespace Matrix;


TEST_CASE("Constructors") {
    SquareMat m1(3);
    m1[{0,0}] = 5;
    m1[{1,1}] = 10;
    m1[{2,2}] = 15;

    CHECK(m1.getSize() == 3);
    CHECK(m1[{0,0}] == 5);
    CHECK(m1[{1,1}] == 10);
    CHECK(m1[{2,2}] == 15);

    // Copy constructor
    SquareMat m2(m1);
    CHECK(m2.getSize() == 3);
    CHECK(m2[{0,0}] == 5);
    CHECK(m2[{1,1}] == 10);
    CHECK(m2[{2,2}] == 15);

    // Assignment operator
    SquareMat m3(2);
    m3[{0,0}] = 1;
    m3 = m1;
    CHECK(m3.getSize() == 3);
    CHECK(m3[{0,0}] == 5);
    CHECK(m3[{1,1}] == 10);
    CHECK(m3[{2,2}] == 15);
}

TEST_CASE("Helper Functions") {
    SquareMat m(2);
    m[{0,0}] = 1;
    m[{0,1}] = 2;
    m[{1,0}] = 3;
    m[{1,1}] = 4;

    CHECK(m.getSize() == 2);
    CHECK(m.sumM() == 10);
}

TEST_CASE("Operator +") {
    SquareMat a(2), b(2) ,c(3);
    a[{0,0}] = 1; a[{1,1}] = 2;
    b[{0,0}] = 2; b[{1,1}] = 3;
    SquareMat d = a + b;
    CHECK(d[{0,0}] == 3);
    CHECK(d[{1,1}] == 5);
    CHECK_THROWS_AS(a + c, std::invalid_argument);
}

TEST_CASE("Operator -") {
    SquareMat a(2), b(2), c(3);
    a[{0,0}] = 5; a[{1,1}] = 10;
    b[{0,0}] = 2; b[{1,1}] = 15;
    SquareMat d = a - b;
    CHECK(d[{0,0}] == 3);
    CHECK(d[{1,1}] == -5);
    CHECK_THROWS_AS(a - c, std::invalid_argument);
}

TEST_CASE("Operator * (matrix)") {
    SquareMat a(2), b(2) ,c(3);
    a[{0,0}] = 1; a[{0,1}] = 2;
    b[{0,0}] = 3; b[{1,0}] = 4;
    SquareMat d = a * b;
    CHECK(d[{0,0}] == 1*3 + 2*4);
    CHECK_THROWS_AS(a*c, std::invalid_argument);

}
TEST_CASE("Operator * (scalar)") {
    SquareMat a(2);
    a[{0,0}] = 2; a[{0,1}] = 3;
    a[{1,0}] = 4; a[{1,1}] = 5;
    SquareMat c = a * 2;
    CHECK(c[{0,0}] == 4);
    CHECK(c[{0,1}] == 6);
    CHECK(c[{1,0}] == 8);
    CHECK(c[{1,1}] == 10);

}

TEST_CASE("Operator % (matrix)") {
    SquareMat a(2), b(2) ,c(3);
    a[{0,0}] = 1; a[{1,1}] = 2;
    b[{0,0}] = 3; b[{1,1}] = 4;
    SquareMat d = a % b;
    CHECK(d[{0,0}] == 3);
    CHECK(d[{1,1}] == 8);
    CHECK_THROWS_AS(a % c, std::invalid_argument);
}

TEST_CASE("Operator % (scalar)") {
    SquareMat a(2);
    a[{0,0}] = 2; a[{0,1}] = 3;
    a[{1,0}] = 6; a[{1,1}] = 11;
    SquareMat c = a % 2;
    CHECK(c[{0,0}] == 0);
    CHECK(c[{0,1}] == 1);
    CHECK(c[{1,0}] == 0);
    CHECK(c[{1,1}] == 1);
}

TEST_CASE("Operator /") {
    SquareMat a(2);
    a[{0,0}] = 2; a[{0,1}] = 4;
    a[{1,0}] = 6; a[{1,1}] = 8;
    SquareMat c = a / 2;
    CHECK(c[{0,0}] == 1);
    CHECK(c[{0,1}] == 2);
    CHECK(c[{1,0}] == 3);
    CHECK(c[{1,1}] == 4);
    CHECK_THROWS_AS(a / 0, std::invalid_argument);
}

TEST_CASE("Operator ^") {
    SquareMat m(2);
    m[{0,0}] = 1;
    m[{0,1}] = 2;
    m[{1,0}] = 3;
    m[{1,1}] = 4;

    SUBCASE("Power 0") {
        SquareMat id = m ^ 0;
        CHECK(id[{0,0}] == 1);
        CHECK(id[{0,1}] == 0);
        CHECK(id[{1,0}] == 0);
        CHECK(id[{1,1}] == 1);
    }

    SUBCASE("Power 1") {
        SquareMat same = m ^ 1;
        CHECK(same[{0,0}] == 1);
        CHECK(same[{0,1}] == 2);
        CHECK(same[{1,0}] == 3);
        CHECK(same[{1,1}] == 4);
    }

    SUBCASE("Power 2") {
        SquareMat sq = m ^ 2;
        CHECK(sq[{0,0}] == 7);
        CHECK(sq[{0,1}] == 10);
        CHECK(sq[{1,0}] == 15);
        CHECK(sq[{1,1}] == 22);
    }

    SUBCASE("Power 3") {
        SquareMat cubed = m ^ 3;
        CHECK(cubed[{0,0}] == 37);
        CHECK(cubed[{0,1}] == 54);
        CHECK(cubed[{1,0}] == 81);
        CHECK(cubed[{1,1}] == 118);
    }

    SUBCASE("Negative power") {
        CHECK_THROWS_AS(m ^ -1, std::invalid_argument);
    }
}

TEST_CASE("Increment and Decrement operators") {
    SquareMat m(2);
    m[{0,0}] = 1;
    m[{0,1}] = 2;
    m[{1,0}] = 3;
    m[{1,1}] = 4;

    SUBCASE("Prefix ++ operator") {
        ++m;
        CHECK(m[{0,0}] == 2);
        CHECK(m[{0,1}] == 3);
        CHECK(m[{1,0}] == 4);
        CHECK(m[{1,1}] == 5);
    }

    SUBCASE("Prefix -- operator") {
        --m;
        CHECK(m[{0,0}] == 0);
        CHECK(m[{0,1}] == 1);
        CHECK(m[{1,0}] == 2);
        CHECK(m[{1,1}] == 3);
    }

    SUBCASE("Postfix ++ operator") {
        SquareMat before = m++;
        // Check that the returned matrix is the state before increment
        CHECK(before[{0,0}] == 1);
        CHECK(before[{0,1}] == 2);
        CHECK(before[{1,0}] == 3);
        CHECK(before[{1,1}] == 4);
        // Check that the original matrix was incremented
        CHECK(m[{0,0}] == 2);
        CHECK(m[{0,1}] == 3);
        CHECK(m[{1,0}] == 4);
        CHECK(m[{1,1}] == 5);
    }

    SUBCASE("Postfix -- operator") {
        SquareMat before = m--;
        // Check that the returned matrix is the state before decrement
        CHECK(before[{0,0}] == 1);
        CHECK(before[{0,1}] == 2);
        CHECK(before[{1,0}] == 3);
        CHECK(before[{1,1}] == 4);
        // Check that the original matrix was decremented
        CHECK(m[{0,0}] == 0);
        CHECK(m[{0,1}] == 1);
        CHECK(m[{1,0}] == 2);
        CHECK(m[{1,1}] == 3);
    }
}

TEST_CASE("Operator ~") {
    SquareMat m(2);
    m[{0,0}] = 1;
    m[{0,1}] = 2;
    m[{1,0}] = 3;
    m[{1,1}] = 4;

    SquareMat transposed = ~m;

    CHECK(transposed.getSize() == 2);
    CHECK(transposed[{0,0}] == 1);
    CHECK(transposed[{0,1}] == 3);
    CHECK(transposed[{1,0}] == 2);
    CHECK(transposed[{1,1}] == 4);
}





