#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
/*!
*\file
*\brief Definicja klasy Plaszczyzna.
*/

/*!
*\brief Klasa Plaszczyzna.
*
* Klasa definiuje pojecie plaszczyzny sceny po ktorej porusza sie dron.
*/
class Plaszczyzna
{
protected:
    /*!
*\brief Wierzcholki plaszczyzny.
* Pojemnik przechowujacy wspolrzedne wierzcholkow plaszczyzny.
*/
    std::vector<Vector3D> wierz;
    /*!
*\brief Nazwa pliku.
* Przechowuje nazwe pliku zapisu plaszczyzny.
*/
    std::string nazwa;
    /*!
*\brief Ilosc prostych w siatce plaszczyzny.
* Przechowuje ilosc prostych siatki plaszczyzny.
*/
    int licz_prostych;

public:
    /*!
*\brief Konstruktor parametryczny klasy plaszczyzna.
*/
    Plaszczyzna(Vector3D wymiary = Vector3D(), int gestosc_siatki = 10, std::string nazwa = "../datasets/plaszczyzna");
    /*!
 *\brief Operator zabezpieczajacy wyjscia poza zadana skale
 */
    Vector3D &operator[](int index);
    /*!
 *\brief Operator zabezpieczajacy wyjscia poza zadana skale
 */
    Vector3D operator[](int index) const;
    /*!
*\brief Metoda ktora utawia nazwe pliku zapisu plaszczyzny.
*/
    void set_nazwa(std::string nazwa);
    /*!
*\brief Metoda ktora zwraca nazwe pliku zapisu plaszczyzny.
*/
    std::string get_nazwa() const;
    /*!
*\brief Metoda ktora zapisuje plaszczyzne do pliku.
*/
    void zapisz();
};

#endif