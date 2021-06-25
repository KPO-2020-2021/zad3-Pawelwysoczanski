#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH
#include <string>
#include <memory>

/*!
*\file
*\brief Definicja klasy Obiekt_Sceny.
*/

/*!
*\brief Klasa Obiekt_Sceny.
*Klasa definiuje pojecie Obiektow sceny.
*Klasa jest rodzicem dla klas dziedzicznych BrylaGeometryczna i Dron.
*/
class Obiekt_Sceny
{

public:
    /*!
*\brief Metoda wirtualna ustawiajaca wykrycie kolizji na 0
*/
    virtual bool czy_kolizja(shared_ptr<Obiekt_Sceny> ob) = 0;
    /*!
*\brief Metoda wirtualna ustawiajaca nazwe na 0
*/
    virtual std::string get_nazwa() const = 0;
    /*!
*\brief Metoda wirtualna ustawiajaca zapis do pliku na 0
*/
    virtual void zapisz() = 0;
    /*!
*\brief Metoda wirtualna ustawiajaca srodek na 0
*/
    virtual Vector3D get_srodek() const = 0;
    /*!
*\brief Metoda wirtualna ustawiajaca promien na 0
*/
    virtual double promien() = 0;
};

#endif
