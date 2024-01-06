#pragma once
#include <iostream>

//Enumeracija za tip osobe: Uposlenik (0) ili Agent (1)
enum TipOsobe {
	uposlenik, agent
};

class Osoba
{
private:
	char ime[20], prezime[30], username[30], password[20];
	TipOsobe tipOsobe;
public:
	//Konstruktori
	Osoba() {};
	Osoba(const char* ime, const char* prezime, const char* username, const char* password);
	Osoba(const char* ime, const char* prezime, const char* username);

	//Setteri
	void setIme(const char* ime);
	void setPrezime(const char* prezime);
	void setUsername(const char* username);
	void setPassword(const char* password);
	void setPassword();
	void setTipOsobe();
	void setTipOsobe(int tip);
	virtual void oMeni();

	//Getteri
	char* getIme();
	char* getPrezime();
	char* getUsername();
	char* getPassword();
	TipOsobe getTipOsobe();

	//Destruktor
	~Osoba() {};
};

