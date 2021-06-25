#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Prostopadloscian.
*/

/*!
*\brief Klasa Prostopadloscian
*Klasa definiuje pojecie Prostopadloscianu.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Prostopadloscian : public BrylaGeometryczna
{

public:
  /*!
  *\brief Konstruktor parametryczny klasy Prostopadloscian.
  */
    Prostopadloscian(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/prostopadloscian.dat");
    /*!
*\brief Tworzy kopie elementu klasy Prostopadloscian.
*/
    Prostopadloscian(Prostopadloscian &pr);
        /*!
*\brief Operator przypisania dal klasy Prostopadloscian.
*/
    Prostopadloscian &operator=(const Prostopadloscian &other)
    {
        wymiary = other.wymiary;
        wierz = other.wierz;
        srodek = other.srodek;
        nazwa = other.nazwa;
        return *this;
    }
};

#endif