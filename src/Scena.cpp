#include "Scena.hh"

Scena::Scena()
{
/*!
*\brief 
* Tworzy scene po ktorej poruszac sie beda drony.
*/

  Lacze.ZmienTrybRys(PzG::TR_3D);
  nr_elem = 0;
  nr_drona = 0;
  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Vector3D wym_dna(tab_wym);
  dno = new Plaszczyzna(wym_dna, 20);
  Vector3D srod;
  bool kolizja = false;
  for (int i = 0; i < 4; i++)
  {
    cout << "dupa" << endl;
    srod[0] = rand() % 400 - 200;
    srod[1] = rand() % 400 - 200;
    srod[2] = 50;
    int nr_p = rand() % 3;
    if (nr_p == 0)
      Lista_elementow.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    else if (nr_p == 1)
      Lista_elementow.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    else if (nr_p == 2)
      Lista_elementow.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    nr_elem++;
    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_elementow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_elementow.erase(Lista_elementow.begin());
    }
    kolizja = false;
  }
  for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_nazwa().c_str());
    (*a)->zapisz();
    cout << (*a)->get_nazwa() << " " << (*a)->promien() << endl;
  }

  Lacze.DodajNazwePliku(dno->get_nazwa().c_str());
  dno->zapisz();
  kolizja = false;
  for (int i = 0; i < N; i++)
  {
    double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

    Lista_Dronow.push_front(std::make_shared<Dron>(i, Lacze, Vector3D(pozycja)));

    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_Dronow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_Dronow.erase(Lista_Dronow.begin());
    }
    else
    {
      Lista_elementow.push_front(*Lista_Dronow.begin());
      cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
      (*Lista_Dronow.begin())->zapisz();
      nr_drona++;
    }
    kolizja = false;
  }

  Lacze.Rysuj();
}
/*!
*\brief 
*Rysuje Scene 
*/
void Scena::rysuj()
{

  Lacze.Rysuj();
}
/*!
*\brief 
* Odpowiada za interfejs sterowania programem.
*/
bool Scena::interfejs(char opcja)
{

  switch (opcja)
  {
  case 'a':
  {
    cout << "Podaj nr drona ktorego chcesz aktywowac " << endl;
    for (int i = 0; i < (int)Lista_Dronow.size(); i++)
    {
      cout << i << " " << endl;
    }
    cout << ":" << endl;
    int nr;
    cin >> nr;
    Drona = Lista_Dronow.begin();
    for (int i = 0; i < nr; i++)
    {
      Drona++;
    }
    cout << "Dron " << nr << " aktywny" << endl;
  }
  break;
  case 'p':
    (*Drona)->sterowanie(Lista_elementow);
    break;

  case 'd':
  {
    cout << "Ktory element chcesz dodac podaj 1-gora, 2-plaskowyz, 3 gran, 4 dron" << endl;

    int nr;
    cin >> nr;
    Vector3D srod;

    if (nr != 4)
    {
      for (int i = 0; i < 50; i++)
      {
        srod[0] = rand() % 400 - 200;
        srod[1] = rand() % 400 - 200;
        srod[2] = 50;
        bool kolizja = false;
        if (nr == 1)
        {

          Lista_elementow.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
        }
        if (nr == 2)
        {

          Lista_elementow.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
        }
        if (nr == 3)
        {

          Lista_elementow.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
        }

        nr_elem++;
        for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_elementow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {
          i--;
          Lista_elementow.erase(Lista_elementow.begin());
        }
        else
        {
          break;
        }
      }
      (*Lista_elementow.begin())->zapisz();
      Lacze.DodajNazwePliku((*Lista_elementow.begin())->get_nazwa().c_str());
    }
    else
    {
      bool kolizja = false;
      for (int i = 0; i < 50; i++)
      {
        double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        Lista_Dronow.push_front(std::make_shared<Dron>(nr_drona, Lacze, Vector3D(pozycja)));

        for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_Dronow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {

          Lista_Dronow.erase(Lista_Dronow.begin());
        }
        else
        {
          Lista_elementow.push_front(*Lista_Dronow.begin());
          cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
          (*Lista_Dronow.begin())->zapisz();
          nr_drona++;
          break;
        }
        kolizja = false;
      }
    }
  }

  break;
  case 'u':
  {
    int i = 0;
    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      cout << i << ": " << (*a)->get_nazwa() << endl;
      i++;
    }
    cout << "podaj numer" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    Lacze.UsunNazwePliku((*a)->get_nazwa());
    Lista_elementow.erase(a);
  }
  break;

  default:
    break;
  }

  return true;
}
/*!
*\brief 
* Usuwa tablice dronow.
*/
Scena::~Scena()
{
  free(dno);
}