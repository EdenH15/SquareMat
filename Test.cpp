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

