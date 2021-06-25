#ifndef GORA_HH
#define GORA_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Gora.
*/

/*!
*\brief Klasa Gora.
*Klasa definiuje pojecie Gory.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Gora : public BrylaGeometryczna
{

public:
  /*!
*\brief Metoda zwraca wskaxnik na wartosc z wymiaru bryly.
*/
  double promien() { return (*wymiary)[2]; }
  /*!
*\brief Konstruktor parametryczny klasy Gora.
*/
  Gora(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/Gora.dat");
  /*!
*\brief Tworzy kopie elementu klasy Gora.
*/
  Gora(Gora &pr);
  /*!
*\brief Operator przypisania dal klasy Gora.
*/
  Gora &operator=(const Gora &other)
  {
    wymiary = other.wymiary;
    wierz = other.wierz;
    srodek = other.srodek;
    nazwa = other.nazwa;
    return *this;
  }
};

#endif