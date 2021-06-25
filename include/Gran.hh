#ifndef GRAN_HH
#define GRAN_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Gran.
*/

/*!
*\brief Klasa Gran.
*Klasa definiuje pojecie Grani.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Gran : public BrylaGeometryczna
{

public:
    /*!
*\brief Konstruktor parametryczny klasy Gran.
*/
    Gran(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/Gran.dat");
    /*!
*\brief Tworzy kopie elementu klasy Gran.
*/
    Gran(Gran &pr);
    /*!
*\brief Operator przypisania dal klasy Gran.
*/
    Gran &operator=(const Gran &other)
    {
        wymiary = other.wymiary;
        wierz = other.wierz;
        srodek = other.srodek;
        nazwa = other.nazwa;
        return *this;
    }
};

#endif