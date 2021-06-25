
#include "Dron.hh"
/*!
*\brief 
* Konstruktor tworzy model drona ktorego elementy skladowe zapisuje osobno do pliku zlozone z prostopadloscianu oraz graniastoslupow.
*/
Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja) : Lacze(Lacze)
{
    kat = 0;
    this->id = id;

    orginal.set_nazwa("../datasets/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        org_wir[i].set_nazwa("../datasets/wirnik" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.get_nazwa().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(org_wir[i].get_nazwa().c_str());
    kopia = orginal;
    promien_ = kopia.promien();
    kopia.przesun(pozycja);
    for (int i = 0; i < 4; i++)
        kopia_wir[i] = org_wir[i];

    for (int i = 0; i < 4; i++)
        kopia_wir[i].przesun(orginal[i * 2] + pozycja);

    this->droga = this->droga + pozycja;
}
/*!
  *\brief Metoda ktora wykonuje operacje wznoszenia drona na wysokosc przelotu.
  */
void Dron::unoszenie(double droga)
{
    Vector3D droga_o;
    droga_o[2] = droga;

    this->droga = this->droga + droga_o;
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Przesuniecia drona.
  */
void Dron::przesun(double droga)
{
    Vector3D droga_o;
    droga_o[0] = droga * cos(kat * M_PI / 180);
    droga_o[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_o;
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Obrotu drona.
  */
void Dron::obrot(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obr = nowa * mac_obr_z(this->kat);
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Obrotow rotorow drona.
  */
void Dron::obrot_rotrow()
{
    static int kat = 0;
    kat += 3;
    if (kat == 360)
        kat = 0;

    Macierz3x3 nowa, nowa2;

    for (int i = 0; i < 4; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            nowa = nowa * mac_obr_z(kat);
            kopia_wir[i].translacja(nowa);
        }
        else
        {
            nowa2 = nowa2 * mac_obr_z(-kat);
            kopia_wir[i].translacja(nowa2);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        kopia_wir[i].przesun(kopia[i * 2]);
    }
}
/*!
  *\brief Metoda ktora wykonuje operacje zapisu drona do pliku.
  */
void Dron::zapisz()
{
    kopia.zapisz();
    for (int i = 0; i < 4; i++)
        kopia_wir[i].zapisz();
}
/*!
  *\brief Metoda ktora wykonuje operacje sterowania dronem.
  */
void Dron::sterowanie(std::list<std::shared_ptr<Obiekt_Sceny>> &Lista_elementow)
{
    double droga;
    double kat;

    zapisz();
    cout << "Podaj kierunek lotu (kat w stopniach)>";
    cin >> kat;
    cout << "Podaj ddlugosc lotu> ";
    cin >> droga;
    Lacze.DodajNazwePliku("../datasets/droga.dat");
    okresl_droge(droga, kat);
    cout << "Wznosznie..." << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginal;
        for (int j = 0; j < 4; j++)
            kopia_wir[j] = org_wir[j];
        unoszenie(1);
        obrot_rotrow();
        zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    bool kolizja = false;
    if (kat > 0)
    {
        for (int i = 0; i < kat; i++)
        {
            kopia = orginal;
            for (int i = 0; i < 4; i++)
                kopia_wir[i] = org_wir[i];
            obrot(1);
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }
    else
    {
        for (int i = 0; i > kat; i--)
        {
            kopia = orginal;
            obrot(-1);
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }
    while (1)
    {

        for (int i = 0; i < droga; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            przesun(1);
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }

        for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
            kopia = orginal;
            unoszenie(-100);
            if (czy_kolizja(*a))
            {
                cout << (*a)->get_nazwa() << endl;
                kolizja = true;
            }
            kopia = orginal;
            unoszenie(100);
        }

        if (!kolizja)
        {
            break;
        }
        kolizja = false;
        droga = 40;
        okresl_droge(droga, kat);
    }
    for (int i = 0; i < 100; i++)
    {
        kopia = orginal;
        for (int j = 0; j < 4; j++)
            kopia_wir[j] = org_wir[j];
        unoszenie(-1);
        obrot_rotrow();
        zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    Lacze.UsunNazwePliku("../datasets/droga.dat");
}
Vector3D Dron::get_srodek() const
{
    return kopia.get_srodek();
}
/*!
*\brief
* Metoda przy pomocy metody promien() sprawdza czy dron w czasie przelotu i ladowania nie koliduje z elementami znajudjacymi sie na scenie 
*/
bool Dron::czy_kolizja(shared_ptr<Obiekt_Sceny> ob)
{
    std::shared_ptr<Dron> self = shared_from_this();

    if (ob != self)
    {

        Vector3D srodek_Drona = kopia.get_srodek();
        Vector3D srodek_Obiektu = ob->get_srodek();
        double l = sqrt(pow(srodek_Drona[0] - srodek_Obiektu[0], 2) + pow(srodek_Drona[1] - srodek_Obiektu[1], 2) + pow(srodek_Drona[2] - srodek_Obiektu[2], 2));
        if (promien_ + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}
/*!
  *\brief Metoda ktora wykonuje operacje rysowania trasy przelotu drona.   
  */
void Dron::okresl_droge(double droga, double kat)
{
    std::cout << "Rysuje sciezke przelotu" << endl;
    Vector3D nastepny = kopia.get_srodek();
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);
    nastepny[2] = 100;
    droga_drona.push_back(nastepny);
    nastepny[0] += droga * cos((this->kat + kat) * M_PI / 180);
    nastepny[1] += droga * sin((this->kat + kat) * M_PI / 180);
    droga_drona.push_back(nastepny);
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);
    std::fstream plik;

    plik.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)droga_drona.size(); i++)
    {

        plik << droga_drona[i] << std::endl;
    }
    plik.close();
}
