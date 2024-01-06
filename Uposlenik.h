#pragma once
#include "Osoba.h"
#include <vector>
using std::vector;

class Uposlenik :
    public Osoba
{
private:
    double plataUposlenika;
public:
    //Konstruktori
    Uposlenik() {
        this->plataUposlenika = 0;
    };
    Uposlenik(const char* ime, const char* prezime, const char* username, const char* password, double plataUposlenika) : Osoba(ime, prezime, username, password) {
        this->plataUposlenika = plataUposlenika;
    };
    Uposlenik(const char* ime, const char* prezime, const char* username) : Osoba(ime, prezime, username) {};

    //Setteri
    void setPlataUposlenika();
    void promijeniPlatuUposlenika(double noviIznos);

    //Getteri
    double getPlataUposlenika();

    //Destruktor
    ~Uposlenik() {}
};

