#pragma once
#include "Osoba.h"
#include <vector>
using std::vector;

class Agent :
    public Osoba
{
private:
    double prihodiFirme;
public:
    //Konstruktori
    Agent() {
        this->prihodiFirme = 0;
    };
    Agent(const char* ime, const char* prezime, const char* username, const char* password, double prihodiFirme) : Osoba(ime, prezime, username, password) {
        this->prihodiFirme = prihodiFirme;
    };
    Agent(const char* ime, const char* prezime, const char* username) : Osoba(ime, prezime, username) {};

    //Setteri
    void setPrihodiFirme();
    void updatePrihodiFirme(double iznos_prihoda);
    void promijeniPrihodiFirme(double noviIznos);
    virtual void oMeni();


    double getPrihodiFirme();

    //preoptereceni operato za ispis
    friend std::ostream& operator<<(std::ostream& stream, Agent& a);

    //Destruktor
    ~Agent() {};
};

