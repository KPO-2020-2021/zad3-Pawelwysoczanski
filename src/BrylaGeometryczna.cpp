#include "BrylaGeometryczna.hh"
/*!
*\brief 
*/
Vector3D &BrylaGeometryczna::operator[](int index)
{
    return wierz[index];
}
/*!
*\brief 
*/
Vector3D BrylaGeometryczna::operator[](int index) const
{
    return wierz[index];
}
/*!
*\brief 
*/
void BrylaGeometryczna::set_nazwa(std::string nazwa)
{
    this->nazwa = nazwa;
}
/*!
*\brief 
*/
void BrylaGeometryczna::set_srodek(Vector3D srodek)
{
    this->srodek = srodek;
}
/*!
*\brief 
*/
Vector3D BrylaGeometryczna::get_srodek() const
{
    return srodek;
}
/*!
*\brief 
*/
std::string BrylaGeometryczna::get_nazwa() const
{
    return nazwa;
}
/*!
 *\brief 
 * Metoda pokolei przeuswa kazdy wierzcholek bryly geometrycznej
 * o zadany wektro, na koncu przesuwa tez srodek samej bryly. 
 */
void BrylaGeometryczna::przesun(Vector3D przes)
{
    for (int i = 0; i < (int)wierz.size(); i++)
    {
        wierz[i] = wierz[i] + przes;
    }
    srodek = srodek + przes;
}
/*!
 *\brief 
 * Metoda pokolei mnozy kazdy wierzcholek bryly geometrycznej 
 * razy macierz, na koniec operacje wykonuje rowniez na srodku
 * bryly.
 */
void BrylaGeometryczna::translacja(Macierz3x3 obr)
{
    for (int i = 0; i < (int)wierz.size(); i++)
    {
        wierz[i] = (obr * wierz[i]);
    }
    srodek = obr * srodek;
}
/*!
 *\brief
 * Metoda otwiera plik do ktorego przekazuje pokolei wspolrzedne wierzcholkow
 * bryly , na koniec w celu poprwanego rysowania bryly zapisu dwie pierwsze wspolrzedne.
 */
void BrylaGeometryczna::zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*wymiary)[2] / 2};
    Vector3D przesun_sr(tab);

    plik.open(nazwa, std::ios::out);

    for (int i = 0; i < (int)wierz.size(); i += 2)
    {
        plik << srodek + przesun_sr << std::endl;
        for (int j = 0; j < 2; j++)
        {
            plik << wierz[j + i] << std::endl;
        }
        plik << srodek - przesun_sr << std::endl
             << std::endl;
    }

    plik << srodek + przesun_sr << std::endl;
    for (int j = 0; j < 2; j++)
    {
        plik << wierz[j] << std::endl;
    }
    plik << srodek - przesun_sr << std::endl
         << std::endl;
    plik.close();
}
/*!
*\brief
* Metoda przy pomocy metody promien() sprawdza czy dron w czasie przelotu i ladowania nie koliduje z elementami znajudjacymi sie na scenie 
*/
bool BrylaGeometryczna::czy_kolizja(shared_ptr<Obiekt_Sceny> ob)
{
    std::shared_ptr<BrylaGeometryczna> self = shared_from_this();

    if (ob != self)
    {

        Vector3D srodek_BrylaGeometryczna = get_srodek();
        Vector3D srodek_Obiektu = ob->get_srodek();
        double l = sqrt(pow(srodek_BrylaGeometryczna[0] - srodek_Obiektu[0], 2) + pow(srodek_BrylaGeometryczna[1] - srodek_Obiektu[1], 2) + pow(srodek_BrylaGeometryczna[2] - srodek_Obiektu[2], 2));
        if (promien() + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}