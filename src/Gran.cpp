#include "Gran.hh"
/*!
*\brief Konstruktor parametryczny klasy Gran.
*/
Gran::Gran(Vector3D srodek, double x, double y, double z, std::string nazwa)
{
  double tab[] = {x, y, z};
  wymiary = std::make_shared<Vector3D>(tab);
  this->nazwa = nazwa;
  this->srodek = srodek;

  Vector3D punkt;

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] - (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] - (z / 2);
  wierz.push_back(punkt);

  punkt[0] = srodek[0] + (x / 2);
  punkt[1] = srodek[1] + (y / 2);
  punkt[2] = srodek[2] - (z / 2);
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

  this->srodek[0] = srodek[0];
  this->srodek[1] = srodek[1];
  this->srodek[2] = srodek[2] - (z / 2);
}
/*!
*\brief Tworzy kopie elementu klasy Gran.
*/
Gran::Gran(Gran &pr)
{
  wymiary = pr.wymiary;
  wierz = pr.wierz;
  srodek = pr.srodek;
  nazwa = pr.nazwa;
}
