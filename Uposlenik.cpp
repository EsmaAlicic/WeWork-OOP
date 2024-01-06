#include "Uposlenik.h"
using std::cout;

void Uposlenik::setPlataUposlenika()
{
    std::cout << "Unesite platu uposlenika: ";
    std::cin >> this->plataUposlenika;
}

void Uposlenik::promijeniPlatuUposlenika(double noviIznos)
{
    this->plataUposlenika = noviIznos;
}

double Uposlenik::getPlataUposlenika()
{
    return this->plataUposlenika;
}

