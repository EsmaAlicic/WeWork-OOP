#include "Posao.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;

Posao::Posao()
{

}

int Posao::getIdPosao() {
    return this->idPosao;
}

int Posao::getPlata()
{
    return this->plata;
}

TipPosla Posao::getTipPosla() {
    return this->tipRada;
}

Firma Posao::getFirma() {
    return this->firma;
}

Osoba Posao::getAgent() {
    return this->agent;
}

int Posao::getZavrsen() {
    return this->zavrsen;
}

void Posao::setIdPosao(int id) {
    this->idPosao = id;
}

void Posao::setTipPosla() {
    int izbor;
    cout << "\t\t\tOdaberite tip Posala: \n";
    cout << "\t\t\t\t1. Frontend\n";
    cout << "\t\t\t\t2. Backend\n";
    do {
        cout << "\t\t\tOdabir: ";
        cin >> izbor;
    } while (izbor < 1 || izbor > 2);
    this->tipRada = (TipPosla)izbor;
}

void Posao::setPlata(int netto)
{
    this->plata = netto;
}

void Posao::setFirma(Firma firma) {
    this->firma = firma;
}

void Posao::setAgent(Osoba agent) {
    this->agent = agent;
}

void Posao::setZavrsen(int stanje) {
    this->zavrsen = stanje;
}

void Posao::promijeniStanje() {
    this->zavrsen = ~this->zavrsen;
}

Posao operator!(Posao& pos) {
    if (pos.getZavrsen() != 1) {
        pos.setZavrsen(1);
    }
    return pos;
}

std::ostream& operator<<(std::ostream& stream, Posao& pos) {
    stream << "\t";
    stream << "|" << setw(6) << left << pos.getIdPosao();
    stream << "|" << setw(15) << left << pos.getAgent().getIme();
    stream << "|" << setw(21) << left << pos.getAgent().getPrezime();
    stream << "|" << setw(24) << left << pos.getAgent().getUsername();
    if (pos.getTipPosla() == (TipPosla)1) {
        stream << setw(19) << left << "|Frontend";
    }
    else stream << setw(19) << left << "|Backend";
    stream << "|" << setw(15) << left << pos.getFirma().getLokacija();
    stream << "|" << setw(8) << left << pos.getFirma().getBrojUposlenih();
    stream << "|" << setw(19) << left << pos.getPlata();

    if (pos.getZavrsen() == 0) {
        stream << setw(17) << left << "|Aktivan" << "|";
    }
    else stream << setw(17) << left << "|Zavrsen" << "|";
    stream << endl;
    return stream;
}

Posao::~Posao()
{
}