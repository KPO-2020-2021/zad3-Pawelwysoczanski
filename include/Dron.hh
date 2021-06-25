#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"
#include "Obiekt_Sceny.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 30000
/*!
*\file
*\brief Definicja klasy Dron.
*/

/*!
*\ 
*Klasa definiuje pojecie Drona sklasdajacego sie z korpusu w postaci prostopadloscianu
*Dziedziczy po klasie wirtualnej Obiekt_Secny oraz klasie enable_shared_from_this.
*oraz 4 rotorow zbudowanych z graniastoslupow.
*/
class Dron : public Obiekt_Sceny, public std::enable_shared_from_this<Dron>
{
  /*!
  *\brief Zmienna przechowujaca promien drona.
  */
  double promien_;
  /*!
  *\brief Droga przelotu drona.
  *Przechowuje wektory polozenia przelotu drona.
  */
  std::vector<Vector3D> droga_drona;
  /*!
  *\brief Lacze umozliwajace rysowanie w programie GNUPlot.
  */
  PzG::LaczeDoGNUPlota &Lacze;
  /*!
  *\brief Oryginalny prostopadloscian.
  *Przechowuje oryginalny prostopadloscina.
  */
  Prostopadloscian orginal;
  /*!
  *\brief Kopia prostopadloscianu
  *Przechowuje kopie prostopadloscianu.
  */
  Prostopadloscian kopia;
  /*!
  *\brief Oryginalne rotory drona.
  *Przechowuje oryginalna tablice Graniastoslupow.
  */
  Graniastoslup6 org_wir[4];
  /*!
  *\brief Kopia oryginalnych rotorow drona.
  *Przechowuje kopie oryginalnej tabliczy Graniastoslupow.
  */
  Graniastoslup6 kopia_wir[4];
  /*!
  *\brief Macierz obrotu drona.
  *Przechowuje macierz obrotu drona.
  */
  Macierz3x3 obr;
  /*!
  *\brief Wektor punktu docelowego drona.
  *Przechowuje wpolrzedne drogi drona.
  */
  Vector3D droga;
  /*!
  *\brief Kat obrotu drona.
  *Przechowuje kat o jaki ma sie obrocic dron.
  */
  double kat;
  /*!
  *\brief Id drona.
  *Przechowuje nr id drona.
  */
  int id;

public:
  /*!
*\brief Metoda zwraca promien kopi drona.
*/
  double promien() { return kopia.promien(); }
  /*!
*\brief Metoda zwraca srodek kopi drona.
*/
  Vector3D get_srodek() const;
  /*!
*\brief Metoda sprawdzajaca wystapienie kolizji z elementami sceny
*/
  bool czy_kolizja(shared_ptr<Obiekt_Sceny> ob);

  void usun();

  std::string get_nazwa() const { return "dron"; }
  /*!
*\brief  Metoda zwraca Id drona.
*/
  int get_id() { return id; }
  /*!
  *\brief Konstruktor parametryczny klasy dron.
  */
  Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja);
  /*!
  *\brief Metoda ktora wykonuje operacje unoszenia drona na wysokosc przelotu.
  */
  void unoszenie(double droga);
  /*!
  *\brief Metoda ktora wykonuje operacje przesuniecia drona.
  */
  void przesun(double droga);
  /*!
  *\brief Metoda ktora wykonuje operacje obrotu drona.
  */
  void obrot(double kat);
  /*!
  *\brief Metoda ktora wykonuje operacje obrotow rotorow drona.
  */
  void obrot_rotrow();
  /*!
  *\brief Metoda ktora wykonuje operacje zapisu drona do pliku.
  */
  void zapisz();
  /*!
  *\brief Metoda ktora wykonuje operacje sterowania dronem.
  */
  void sterowanie(std::list<std::shared_ptr<Obiekt_Sceny>> &Lista_elementow);
  /*!
  *\brief Metoda ktora wykonuje operacje rysowania trasy przelotu drona.   
  */
  void okresl_droge(double droga, double kat);
};

#endif
