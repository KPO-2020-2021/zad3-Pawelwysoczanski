#pragma once

#include "size.hh"
#include <iostream>
#include "vector.hh"


class Rectangle
{

private:
    Vector size[SIZE_VERTEX]; //Tablica wektora

public:
    Rectangle();

    Rectangle(const Vector &vector, double height, double width);

    Rectangle operator+(const Vector &vector);

    Rectangle operator-(const Vector &vector);

    const Vector &operator[](int index) const;

    Vector &operator[](int index);

    void translation(const Vector &vector);

    void length();

};
/******************************************************************************
 |  Realizuje prownanie przeciwleglych bokow prostokata                       |
 |  Argumenty:                                                                |
 |      brak                                                                  |
 |  Zwraca:                                                                   |
 |      Komunikat jesli dlugosci bokow sa identyczne lub sie roznia           |
 */
void Rectangle::length()
{
    double side1 = size[0].length(size[1]);
    double side2 = size[2].length(size[3]);
    double side3 = size[2].length(size[1]);
    double side4 = size[0].length(size[3]);

    if (side1 == side2)
    {
        std::cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << std::endl
                  << "    Dlugosc pierwszego boku: " << side1 << std::endl
                  << "      Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout << std::endl;
    }
    else if (side1 != side2)
    {
        std::cout << ":o Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
                  << "    Dlugosc pierwszego boku: " << side1 << std::endl
                  << "      Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout << std::endl;
    }
    if (side3 == side4)
    {
        std::cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << std::endl
                  << "    Dlugosc pierwszego boku: " << side3 << std::endl
                  << "      Dlugosc drugiego boku: " << side4 << std::endl;
        std::cout << std::endl;
    }
    else if (side3 != side4)
    {
        std::cout << ":o Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
                  << "    Dlugosc pierwszego boku: " << side3 << std::endl
                  << "      Dlugosc drugiego boku: " << side4 << std::endl;
        std::cout << std::endl;
    }
}
/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostokata o zadany wktor.            |
 |  Argumenty:                                                                |
 |      vector - wektora o jaki ma zostac przesuniety prostokat.              |
 |  Zwraca:                                                                   |
 |      Przesuniety prostokat o zadany wektor                                 |
 */
void Rectangle::translation(const Vector &vector)
{
    *this = *this + vector;
}
Rectangle::Rectangle()
{
}
/******************************************************************************
 |  Konstruktor klasy Rectangle                                               |
 |  Argumenty:                                                                |
 |      vector - wektora o jaki ma zostac przesuniety prostokat.              |
 |      height - zmiana polozenia wierzcholka prostokata w osi y.             |
 |       width - zmiana polozenia wierzcholka prostokata w osi x.             |
 |  Zwraca:                                                                   |
 |      Przesuniete wierzcholki prostokata o podany w argumencie wektor       |
 */
Rectangle::Rectangle(const Vector &vector, double height, double width)
{
    for (int i = 0; i < SIZE_VERTEX; i++)
        size[i] = vector;

    size[1][0] += width;
    size[2][0] += width;
    size[2][1] += height;
    size[3][1] += height;
}
/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Rectangle Rectangle::operator+(const Vector &vector)
{
    Rectangle result;
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        result[i] = size[i] + vector;
    }
    return result;
}
/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Rectangle Rectangle::operator-(const Vector &vector)
{
    Rectangle result;
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        result[i] = size[i] - vector;
    }
    return result;
}
/******************************************************************************
 |  Funktor prostokata.                                                       |
 |  Argumenty:                                                                |
 |      index - index prostokata.                                             |
 |  Zwraca:                                                                   |
 |      Wartosc prostokata w danym miejscu tablicy jako stala.                |
 */
const Vector &Rectangle::operator[](int index) const
{
    if (index < 0 || index >= SIZE_VERTEX)
    {
        throw "Error: Prostokat jest poza zasiegiem!";
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}
/******************************************************************************
 |  Funktor prostokata.                                                       |
 |  Argumenty:                                                                |
 |      index - index prostokata.                                             |
 |  Zwraca:                                                                   |
 |      Wartosc prostokata w danym miejscu tablicy jako zmienna.              |
 */
Vector &Rectangle::operator[](int index)
{
    if (index < 0 || index >= SIZE_VERTEX)
    {
        throw "Error: Prostokat jest poza zasiegiem!";
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}
/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - prostokąt.                                                      |
 */
std::ostream &operator<<(std::ostream &out, Rectangle const &tmp)
{
    for (int i = 0; i < SIZE_VERTEX; ++i)
    {
        out << tmp[i] << std::endl;
    }
    return out;
}
