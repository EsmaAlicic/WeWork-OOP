#include "Osoba.h"
#include <iostream>

using std::cout;
using std::cin;

Osoba::Osoba(const char* ime, const char* prezime, const char* username, const char* password) {
	strcpy_s(this->ime, ime);
	strcpy_s(this->prezime, prezime);
	strcpy_s(this->username, username);
	strcpy_s(this->password, password);
}

Osoba::Osoba(const char* ime, const char* prezime, const char* username) {
	strcpy_s(this->ime, ime);
	strcpy_s(this->prezime, prezime);
	strcpy_s(this->username, username);
}

void Osoba::setIme(const char* ime) {
	strcpy_s(this->ime, ime);
}

void Osoba::setPrezime(const char* prezime) {
	strcpy_s(this->prezime, prezime);
}

void Osoba::setUsername(const char* username) {
	strcpy_s(this->username, username);
}

void Osoba::setPassword(const char* password) {
	strcpy_s(this->password, password);
}


void Osoba::setPassword() {
	do {
		cout << "Unesite password: ";
		cin.getline(this->password, 20);
	} while (strlen(this->password) < 6);
}


void Osoba::setTipOsobe(int tip) {
	this->tipOsobe = TipOsobe(tip);
}

void Osoba::oMeni() {
	cout << "Ja sam osoba!\n";
}

void Osoba::setTipOsobe() {
	int x;
	do {
		cout << "Unesite tip osobe: ";
		cin >> x;
	} while (x > 2 || x < 0);
	this->tipOsobe = TipOsobe(x);
}

char* Osoba::getIme() {
	return this->ime;
}

char* Osoba::getPrezime() {
	return this->prezime;
}

char* Osoba::getUsername() {
	return this->username;
}

char* Osoba::getPassword() {
	return this->password;
}


TipOsobe Osoba::getTipOsobe() {
	return this->tipOsobe;
}
