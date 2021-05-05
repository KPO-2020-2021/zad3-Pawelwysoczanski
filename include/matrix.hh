#include "size.hh"
#include "vector.hh"
#include "rectangle.hh"
#include <cmath>
#include <iostream>
#include <cstdlib>

class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy

public:
    Matrix(double[SIZE][SIZE]); // Konstruktor klasy

    Matrix(); // Konstruktor klasy

    Vector operator*(Vector tmp); // Operator mnożenia przez wektor

    Rectangle operator*(Rectangle tmp); // Operator mnozenia macierzy

    Matrix operator+(Matrix tmp); // Operator dodawnia macierzy

    bool operator==(const Matrix &m) const; // Operator porownania macierzy

    bool operator!=(const Matrix &m) const; //Operator porownania macierzy

    double &operator()(unsigned int row, unsigned int column);

    const double &operator()(unsigned int row, unsigned int column) const;

    void Calculate(double kat);
};
/******************************************************************************
 |  Realizuje porownanie dwoch macierzy.                                      |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik porownania,                   |
 |      m - macierz, czyli drugi skladnik porownania.                         |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Matrix::operator!=(const Matrix &m) const
{
    return !(*this == m);
}
/******************************************************************************
 |  Realizuje porownanie dwoch macierzy.                                      |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik porownania,                   |
 |      m - macierz, czyli drugi skladnik porownania.                         |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Matrix::operator==(const Matrix &m) const
{
    bool wynik = true;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if ((value[i][j] != m.value[i][j]))
                wynik = false;
        }
    }
    return wynik;
}
std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = tmp[i][j];
        }
    }
}
/******************************************************************************
|  Tworzy macierz rotacji i wylicza jej skałdniki podane z przez uzytkownika  | 
|  Argumenty:                                                                 |
|       angle - kat o jaki ma zostac obrocony prostokat                       |
|  Zwraca:                                                                    |
|                                                                             |
*/
void Matrix::Calculate(double angle)
{
    double radian = angle * M_PI / 180;
    value[0][0] = cos(radian);
    value[0][1] = -sin(radian);
    value[1][0] = sin(radian);
    value[1][1] = cos(radian);
}
/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator*(Vector tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}
/******************************************************************************
 |  Realizuje mnozenie macierzy i wierzcholkow prostokata.                    |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia,                                    |
 |      tmp - drugi skladnik mnozenia.                                        |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Rectangle Matrix::operator*(Rectangle tmp)
{
    Rectangle result;
    for (int i = 0; i < SIZE_VERTEX; ++i)
    {

        result[i] = *this * tmp[i];
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column)
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator()(unsigned int row, unsigned int column) const
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
Matrix Matrix::operator+(Matrix tmp)
{
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
 */
std::istream &operator>>(std::istream &in, Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
