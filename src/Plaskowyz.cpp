#include "Plaskowyz.hh"
/*!
*\brief Konstruktor parametryczny klasy Plaksowyz.
*/
Plaskowyz::Plaskowyz(Vector3D srodek, double x, double y, double z, std::string nazwa)
{
  double tab[] = {x, y, z};
  wymiary = std::make_shared<Vector3D>(tab);
  this->nazwa = nazwa;
  this->srodek = srodek;
  Vector3D punkt;

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] + (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] + (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] + (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] + (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] + (x / 2);
  punkt[1] = srodek[1] - (y / 2);
  punkt[2] = srodek[2] + (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] + (x / 2);
  punkt[1] = srodek[1] - (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] - (y / 2);
  punkt[2] = srodek[2] + (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] - (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);
}
/*!
*\brief Tworzy kopie elementu klasy Plaskowyz.
*/
Plaskowyz::Plaskowyz(Plaskowyz &pr)
{
  wymiary = pr.wymiary;
  wierz = pr.wierz;
  srodek = pr.srodek;
  nazwa = pr.nazwa;
}