#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Graniastoslup6.
*/

/*!
*\brief Klasa Graniastoslup6.
*Klasa definiuje pojecie Graniastoslupa.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Graniastoslup6 : public BrylaGeometryczna
{
    public:
        /*!
*\brief Konstruktor parametryczny klasy Graniastoslup6
*/
    Graniastoslup6(Vector3D srodek=Vector3D(),double z=10,double promien=15,std::string nazwa = "../datasets/garniastoslup6.dat" );
   
};




#endif
