#include "Firma.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::ostream;

Firma::Firma(const char* naziv, int brojUposlenih, const char* lokacija, int plata)
{
    this->brojUposlenih = brojUposlenih;
    strcpy_s(this->lokacija, lokacija);
}

void Firma::setNaziv()
{
    cin.ignore();
    string naziv;
    cout << "\t\t\tUnesite naziv firme: \t\t\t";
    getline(cin, naziv);
}

void Firma::setBrojUposlenih()
{
    cout << "\t\t\tOdaberite broj uposlenih: \t\t\t\n";
    int izbor;
    cin >> izbor;
    this->brojUposlenih = izbor;
}

void Firma::setLokacija()
{
    cin.ignore();
    cout << "\t\t\tUnesite lokaciju firme: ";
    string lokacija;
    getline(cin, lokacija);
    strcpy_s(this->lokacija, lokacija.c_str());
}

void Firma::setFirma()
{
    const char* crt = "\n\t\t======================================================\n";
    cout << "\n";
    cout << crt << "\t\t\t::REGISTRACIJA NOVE FIRME::" << crt;
    this->setLokacija();
    this->setBrojUposlenih();
    this->setNaziv();
}

void Firma::setAgent(Agent agent)
{
    this->agent = agent;
}

char* Firma::getNaziv()
{
    return this->naziv;
}

int Firma::getBrojUposlenih()
{
    return this->brojUposlenih;
}

char* Firma::getLokacija() {
    return this->lokacija;
}

Agent Firma::getAgent()
{
    return this->agent;
}