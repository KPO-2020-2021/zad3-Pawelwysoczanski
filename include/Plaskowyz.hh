#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Plaskowyz.
*/

/*!
*\brief Klasa Plaskowyz.
*Klasa definiuje pojecie Plaskowyzu.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Plaskowyz : public BrylaGeometryczna
{

public:
    /*!
*\brief Konstruktor parametryczny klasy Plaskowyz.
*/
    Plaskowyz(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/Plaskowyz.dat");
    /*!
*\brief Tworzy kopie elementu klasy Plaskowyz.
*/
    Plaskowyz(Plaskowyz &pr);
    /*!
*\brief Operator przypisania dal klasy PLaskowyz.
*/
    Plaskowyz &operator=(const Plaskowyz &other)
    {
        wymiary = other.wymiary;
        wierz = other.wierz;
        srodek = other.srodek;
        nazwa = other.nazwa;
        return *this;
    }
};

#endif