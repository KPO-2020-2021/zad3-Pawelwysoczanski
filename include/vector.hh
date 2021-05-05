#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>

class Vector
{

private:
    double size[SIZE]; //Tablica wektora

public:
    Vector();

    Vector(double[SIZE]);

    Vector operator+(const Vector &v);

    Vector operator-(const Vector &v);

    Vector operator*(const double &tmp);

    Vector operator/(const double &tmp);

    const double &operator[](int index) const;

    bool operator==(const Vector &v) const;

    bool operator!=(const Vector &v) const;

    double &operator[](int index);

    double length(const Vector &v);
};
/******************************************************************************
 |  Realizuje porownanie dwoch wektorow.                                      |
 |  Argumenty:                                                                |
 |      this - vector, czyli pierwszy skladnik porownania,                    |
 |      v- vector, czyli drugi skladnik porownania.                           |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Vector::operator!=(const Vector &v) const
{
    return !(*this == v);
}
/******************************************************************************
 |  Realizuje porownanie dwoch wektorow.                                      |
 |  Argumenty:                                                                |
 |      this - vector, czyli pierwszy skladnik porownania,                    |
 |      v- vector, czyli drugi skladnik porownania.                           |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Vector::operator==(const Vector &v) const
{
    bool wynik = true;
    for (int i = 0; i < SIZE; i++)
    {
        if ((size[i] != v.size[i]))
            wynik = false;
    }
    return wynik;
}
std::ostream &operator<<(std::ostream &out, Vector const &tmp);

std::istream &operator>>(std::istream &in, Vector &tmp);

double Vector::length(const Vector &v)
{
    double suma = 0;
    for (int i = 0; i < SIZE; i++)
        suma += pow(size[i] - v[i], 2);
    return sqrt(suma);
}
/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = 0;
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
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
Vector Vector::operator+(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] += v[i];
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
Vector Vector::operator-(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator*(const double &tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator/(const double &tmp)
{
    Vector result;

    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        throw "Error: Wektor jest poza zasiegiem!";
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator<<(std::ostream &out, Vector const &tmp)
{

    for (int i = 0; i < SIZE - 1; i++)
        out << tmp[i] << " ";

    out << tmp[SIZE - 1];

    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wejsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator>>(std::istream &in, Vector &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
        if (in.fail())
        {
            tmp[0] = 0;
            tmp[1] = 0;
        }
    }
    std::cout << std::endl;
    return in;
}
