#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "rectangle.hh"
#include "vector.hh"
#include "matrix.hh"
#include "size.hh"
#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150
/*Testy dla klasy Vector*/
TEST_CASE("operator +,test 1")
{
    double w1[] = {13, 27};
    double w2[] = {5, 9};
    double w3[] = {18, 36};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    CHECK_EQ(we1 + we2, we3);
}
TEST_CASE("operator +,test 2")
{
    double w1[] = {13.999, 27.999};
    double w2[] = {5.002, 9.002};
    double w3[] = {19.001, 37.001};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    CHECK_EQ(we1 + we2, we3);
}
TEST_CASE("operator -,test 1")
{
    double w1[] = {13, 27};
    double w2[] = {5, 9};
    double w3[] = {8, 18};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);
    Vector we4;

    we4 = we1 - we2;

    CHECK_EQ(we4, we3);
}
TEST_CASE("operator -,test 2")
{
    double w1[] = {13.99, 27.99};
    double w2[] = {5.01, 9.01};
    double w3[] = {8.98, 18.98};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    CHECK_EQ(we1 - we2, we3);
}
TEST_CASE("Operator wczytywania >>,test 1")
{
    std::stringstream in;

    Vector we1;
    double w[] = {4, 1};
    Vector we2(w);

    in << "4 1" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 2")
{
    std::stringstream in;

    Vector we1;
    double w[] = {0, 1};
    Vector we2(w);

    in << "0 1" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 3")
{
    std::stringstream in;

    Vector we1;
    double w[] = {0, 0};
    Vector we2(w);

    in << "0 0" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 4")
{
    std::stringstream in;

    Vector we1;
    double w[] = {0, 0};
    Vector we2(w);

    in << "p 1" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 5")
{
    std::stringstream in;

    Vector we1;
    double w[] = {0, 0};
    Vector we2(w);

    in << "4 d" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 6")
{
    std::stringstream in;

    Vector we1;
    double w[] = {4.888, -3.444};
    Vector we2(w);

    in << "4.888 -3.444" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 7")
{
    std::stringstream in;

    Vector we1;
    double w[] = {-4, 3};
    Vector we2(w);

    in << "-4 3" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wypisywania <<,test 1")
{
    std::stringstream out;

    double w[] = {-4, 3};

    Vector we1;
    Vector we2(w);

    out << we2;

    CHECK_EQ("-4 3", out.str());
}
TEST_CASE("Operator wypisywania <<,test 2")
{
    std::stringstream out;

    double w[] = {-4.888, 3.444};

    Vector we1;
    Vector we2(w);

    out << we2;

    CHECK_EQ("-4.888 3.444", out.str());
}
TEST_CASE("Konstruktor parametryczny")
{
    double w1[] = {4, 3};
    double w2[] = {6, 8};

    Vector we1(w1);

    CHECK(we1 != Vector(w2));
    CHECK_EQ(we1, Vector(w1));
}
TEST_CASE("Konstruktor bezparametryczny")
{
    Vector we1;
    CHECK_EQ(we1, Vector());
}
TEST_CASE("Operator []")
{
    double w1[] = {6, 7};
    double w2[] = {9, 4};
    double w3[] = {34, 78};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    double x1, x2, x3, y1, y2, y3;
    x1 = 6;
    x2 = 9;
    x3 = 34;
    y1 = 7;
    y2 = 4;
    y3 = 78;

    CHECK(x1 == w1[0]);
    CHECK(y1 == w1[1]);
    CHECK(x2 == w2[0]);
    CHECK(y2 == w2[1]);
    CHECK(x3 == w3[0]);
    CHECK(y3 == w3[1]);
}
/*Testy klasy Matrix*/
TEST_CASE("Konstruktor prametryczny")
{
    double m1[][SIZE] = {{3, 2}, {1, 5}};
    double m2[][SIZE] = {{3, 5}, {6, 7}};

    Matrix ma(m1);

    CHECK(ma == Matrix(m1));
    CHECK(ma != Matrix(m2));
}
TEST_CASE("Konstruktor bezparametryczny")
{
    Matrix ma;
    CHECK_EQ(ma, Matrix());
}
TEST_CASE("Operator *,test 1")
{
    double w1[] = {7, 11};
    double w2[] = {1, 2};
    double m1[][SIZE] = {{3, 2}, {1, 5}};

    Matrix ma1(m1);

    Vector we1(w2);
    Vector we2;
    Vector we3(w1);

    we2 = ma1 * we1;

    CHECK_EQ(we2, we3);
}
TEST_CASE("Operator *,test 2")
{
    double w1[] = {-7, -9};
    double w2[] = {1, -2};
    double m1[][SIZE] = {{-3, 2}, {1, 5}};

    Matrix ma1(m1);

    Vector we1(w2);
    Vector we2;
    Vector we3(w1);

    we2 = ma1 * we1;

    CHECK_EQ(we2, we3);
}
/*Testy dla klasy Rectangle*/
TEST_CASE("Konsturktor bezparametryczny")
{
    Rectangle re;
    CHECK_EQ(re, Rectangle());
}
TEST_CASE("Konstruktor parametryczny")
{
    double w1[] = {3, 4};
    double w2[] = {8, 9};

    Vector we1(w1);
    Vector we2(w2);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we2, DL_KROTKI_BOK, DL_DLUGI_BOK);

    CHECK(re1 != re2);
    CHECK_EQ(re1, Rectangle(we1, DL_KROTKI_BOK, DL_DLUGI_BOK));
}
TEST_CASE("Translacja,test 1")
{
    double w1[] = {3, 4};
    double w2[] = {8, 9};
    double w3[] = {11, 13};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we3, DL_KROTKI_BOK, DL_DLUGI_BOK);

    re1.translation(we2);

    CHECK_EQ(re1, re2);
}
TEST_CASE("Translacja,test 2")
{
    double w1[] = {3, 4};
    double w2[] = {-8, -9};
    double w3[] = {-5, -5};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we3, DL_KROTKI_BOK, DL_DLUGI_BOK);

    re1.translation(we2);

    CHECK_EQ(re1, re2);
}
TEST_CASE("Translacja,test 3")
{
    double w1[] = {3, 4};
    double w2[] = {0, -9};
    double w3[] = {3, -5};

    Vector we1(w1);
    Vector we2(w2);
    Vector we3(w3);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we3, DL_KROTKI_BOK, DL_DLUGI_BOK);

    re1.translation(we2);

    CHECK_EQ(re1, re2);
}
TEST_CASE("Rotacja,test 1")
{
    double w1[] = {3, 4};
    double w2[] = {3, 4};

    Vector we1(w1);
    Vector we2(w2);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we2, DL_KROTKI_BOK, DL_DLUGI_BOK);

    Matrix ma;

    ma.Calculate(90);

    re1 = ma * re1;
    re2 = ma * re2;

    CHECK_EQ(re1, re2);
}
TEST_CASE("Rotacja,test 2")
{
    double w1[] = {3, 4};
    double w2[] = {3, 4};

    Vector we1(w1);
    Vector we2(w2);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
    Rectangle re2(we2, DL_KROTKI_BOK, DL_DLUGI_BOK);

    Matrix ma;

    ma.Calculate(-90);

    re1 = ma * re1;
    re2 = ma * re2;

    CHECK_EQ(re1, re2);
}
TEST_CASE("Długość boków")
{
    double w1[] = {3, 4};

    Vector we1(w1);

    Rectangle re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);

    re1.length();

    CHECK_EQ(re1, re1);
}

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
