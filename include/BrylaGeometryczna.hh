#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
#include <memory>
#include "Obiekt_Sceny.hh"
/*!
*\file
*\brief Definicja klasy BrylaGeometryczna.
*/

/*!
*\brief Klasa BrylaGeometryczna
*Klasa definiuje pojecie bryly geometryacznej.
*Dziedziczy po klasie wirtualnej Obiekt_Secny oraz klasie enable_shared_from_this.
*Klasa jest rodzicem dla klas dziedzicznych Prostopadloscian i Graniastoslup.
*/
class BrylaGeometryczna : public Obiekt_Sceny, public std::enable_shared_from_this<BrylaGeometryczna>
{
protected:
    /*!
 *\brief Wymiary Bryly.
 *Wskaznik na wektor przechowujacy wymiary bryly.
 */
    std::shared_ptr<Vector3D> wymiary;
    /*!
 *\brief Wierzcholki bryly.
 *Pojemnik typu Vector3D przechowujacy wiercholki bryly.
 */
    std::vector<Vector3D> wierz;
    /*!
 *\brief Srodek bryly.
 *Przechowuje wektor polozenia srodka bryly.
 */
    Vector3D srodek;
    /*!
 *\brief Nazwa pliku.
 *Przechowuje nazwe pliku zapisu bryly.
 */
    std::string nazwa;

public:
    /*!
*\brief Metoda sprawdzajaca wystapienie kolizji z elementami sceny
*/
    bool czy_kolizja(shared_ptr<Obiekt_Sceny> ob);
    /*!
*\brief Metoda tworzaca promien dla metody czy_kolizja
*/
    double promien() { return sqrt(pow(srodek[0] - wierz[0][0], 2) + pow(srodek[1] - wierz[0][1], 2) + pow(srodek[2] - wierz[0][2], 2)); }
    /*!
 *\brief Operator zabezpieczajacy wyjscia poza zadana skale
 */
    Vector3D &operator[](int index);
    /*!
 *\brief Operator zabezpieczajacy wyjscia poza zadana skale
 */
    Vector3D operator[](int index) const;
    /*!
 *\brief Metoda ktora ustawia srodek bryly.
 */
    void set_srodek(Vector3D srodek);
    /*!
 *\brief Metoda ktora ustawia nazwe pliku zapisu bryly.
 */
    void set_nazwa(std::string nazwa);
    /*!
 *\brief Metoda ktora zwraca srodek bryly.
 */
    Vector3D get_srodek() const;
    /*!
 *\brief Metoda ktora zwraca nazwe pliku zapisu bryly.
 */
    std::string get_nazwa() const;
    /*!
 *\brief Metoda ktora wykonuje operacje przesuniecia bryly.
 */

    void przesun(Vector3D przes);
    /*!
 *\brief Metoda ktora wykonuje operacje translacji bryly.
 */
    void translacja(Macierz3x3 obr);
    /*!
 *\brief Metoda ktora wykonuje operacje zapisu bryly do pliku
 */
    void zapisz();
};

#endif
