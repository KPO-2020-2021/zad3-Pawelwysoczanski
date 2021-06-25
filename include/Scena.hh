#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <list>
#include "Plaskowyz.hh"
#include "Gran.hh"
#include "Gora.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Obiekt_Sceny.hh"

#define N 2
/*!
*\file
*\brief Definicja klasy Scena.
*/

/*!
*\brief Klasa Scena
*Klasa definiuje pojecie Sceny.
*W klasie sceny definiujemy ilosc dronow znajdujacych sie na scenie oraz wyglad plaszczyzny.
*Sluzy rowniez do wykonywania operacji przelotu drona jak i wyboru odpowiedzniego.
*/

class Scena
{
    /*!
    *\brief Lista elementow znajdujaca sie na scenie 
    */
    std::list<std::shared_ptr<Obiekt_Sceny>> Lista_elementow;
    /*!
    *\brief Lacze umozliwajace rysowanie w programie GNUPlot.
    */
    PzG::LaczeDoGNUPlota Lacze;
    /*!
    *\brief Wskaznik na tablice dronow ktorymi mozna poruszac.
    */
    std::list<std::shared_ptr<Dron>> Lista_Dronow;
    /*!
*\brief  Ilosc elementow znajdujaca sie na scenie.
*/
    int nr_elem;
    /*!
    *\brief Zmienna pozwalajaca na przechowanie numeru obecnie uzywanego drona.
    */
    int nr_drona;
    /*!
    *\brief Wskaznik na PLaszczyzne umozliwiajacy jej wykorzystanie w scenie.
    */
    Plaszczyzna *dno;
    /*!
*\brief  Lista dronow znajdujaca sie na scenie.
*/
    std::list<std::shared_ptr<Dron>>::const_iterator Drona;

public:
    /*!
    *\brief Konstruktor bezparametryczny klasy Scena.
    */
    Scena();
    /*!
    *\brief Metoda ktora rysuje scene.
    */
    void rysuj();
    /*!
    *\brief Metoda ktora sluzy do wybierania opcji programu.
    */
    bool interfejs(char opcja);
    /*!
    *\brief Destruktor klasy Scena.
    */
    ~Scena();
};

#endif
