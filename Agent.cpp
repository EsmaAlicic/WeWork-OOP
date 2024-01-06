#include "Agent.h"
using std::cout;

void Agent::setPrihodiFirme() {
    std::cout << "Unesite prihode firme: ";
    std::cin >> this->prihodiFirme;
}

void Agent::updatePrihodiFirme(double iznos_prihoda) {
    this->prihodiFirme += iznos_prihoda;
}

void Agent::promijeniPrihodiFirme(double noviIznos) {
    this->prihodiFirme = noviIznos;
}

void Agent::oMeni() {
    cout << "Ja sam Agent!\n";
}

double Agent::getPrihodiFirme() {
    return this->prihodiFirme;
}

std::ostream& operator<<(std::ostream& stream, Agent& a) {
    stream << "\n\tLicni podaci osobaa:" << "\n\t\tIme i prezime: " << a.getIme() << " " << a.getPrezime() << "\n\t\tUsername: "
        << a.getUsername() << "\n\t\tPassword: " << a.getPassword() << "\n\t\tStanje racuna: " << a.getPrihodiFirme()
        << "\n\n";
    return stream;
}
