#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <regex>
#include <climits>

#include "Osoba.h"
#include "Agent.h"
#include "Firma.h"
#include "Posao.h"
#include "Uposlenik.h"

//using namespace std;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::to_string;
using std::right;
using std::shared_ptr;
using std::make_shared;




const char* crt = "\n\t\t======================================================\n";
const char* crtt = "\n\t\t\t\t======================================================\n";

//Globalni niz za sve osobe
const int maxBrOsoba = 50;
Osoba* nizOsoba = new Osoba[maxBrOsoba];
int brojOsoba = 0;

//Glavni meni

char loginMeni() {
	int izbor = {};
	
	do {
		system("cls");
		cout << "\n\n\n\n";
		cout << crtt << "\t\t\t\t\t\t::Login / Register::\t" << crtt;
		cout << "\t\t\t\t\t\t1. Login" << endl;
		cout << "\t\t\t\t\t\t2. Register" << endl;
		cout << "\t\t\t\t\t\t3. Napustite sistem" << endl;
		cout << "\n\t\t\t\t\t\tUnesite izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor > 6);
	return izbor;
}

int uposlenikMeni(Uposlenik uposlenik) {
	int izbor = 0;
	do {
		system("cls");
		std::cout << "\n\n\n\n\n\t\t\tPrijavljen kao: " << uposlenik.getIme() << " " << uposlenik.getPrezime() << endl;
		std::cout << "\t\t\t------------------------\n";
		std::cout << "\t\t\t1. Pregled svih dostupnih poslova \n";
		std::cout << "\t\t\t2. Odjava \n";
		std::cout << "\n\t\t\tIzbor: ";
		std::cin >> izbor;
		if (!cin) {
			std::cout << "Invalid input, please enter a valid number" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (izbor < 1 || izbor > 2);
	return izbor;
}

int agentMeni(Osoba osoba) {
	int izbor = 0;
	do {
		system("cls");
		std::cout << "\n\n\n\n\n\t\t\tPrijavljen kao: " << osoba.getIme() << " " << osoba.getPrezime() << endl;
		std::cout << "\t\t\t------------------------\n";
		std::cout << "\t\t\t1. Objava novog posla \n";
		std::cout << "\t\t\t2. Zavrsavanje posla \n";
		std::cout << "\t\t\t3. Pregled objavljenih oglasa \n";
		std::cout << "\t\t\t4. Odjava \n";
		std::cout << "\n\t\t\tIzbor: ";
		std::cin >> izbor;
		if (!cin) {
			std::cout << "Invalid input, please enter a valid number" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (izbor < 1 || izbor > 4);
	return izbor;
}

//Funkcija za upis osobe u "osobe.txt"
void upisiOsobu(Osoba novaOsoba) {
	//Dodavanje korisnika u bazu podataka
	ofstream dodajOsobu("osobe.txt", ios::app);
	dodajOsobu << nizOsoba[brojOsoba].getIme() << " ";
	dodajOsobu << nizOsoba[brojOsoba].getPrezime() << " ";
	dodajOsobu << nizOsoba[brojOsoba].getUsername() << " ";
	dodajOsobu << nizOsoba[brojOsoba].getPassword() << " ";
	dodajOsobu << nizOsoba[brojOsoba].getTipOsobe() << endl;
	dodajOsobu.close();
	brojOsoba++;
};

//Funkcija za upis uposlenika u fajl "uposlenici.txt"
void upisiUposlenika(Uposlenik noviUposlenik) {
	ofstream dodajUposlenika("uposlenici.txt", ios::app);
	dodajUposlenika << noviUposlenik.getIme() << " ";
	dodajUposlenika << noviUposlenik.getPrezime() << " ";
	dodajUposlenika << noviUposlenik.getUsername() << " ";
	dodajUposlenika << noviUposlenik.getPassword() << " ";
	dodajUposlenika << noviUposlenik.getPlataUposlenika() << " ";
	dodajUposlenika.close();
};

//Funkcija za upis agenta u fajl "agent.txt"
void upisiAgenta(Agent noviAgent) {
	ofstream dodajAgenta("agent.txt", ios::app);
	dodajAgenta << noviAgent.getIme() << " ";
	dodajAgenta << noviAgent.getPrezime() << " ";
	dodajAgenta << noviAgent.getUsername() << " ";
	dodajAgenta << noviAgent.getPassword() << " ";
	dodajAgenta << noviAgent.getPrihodiFirme() << endl;
	dodajAgenta.close();
};

//Funkcija za upis posla u fajl agenta koji je postavio posao, te u datoteku "poslovi.txt"
void upisiPosao(Posao noviPosao, string imeFajla) {
	//Upisivanje posla u datoteku agenta koji je dodao posao
	ofstream upisiLicniPosao(imeFajla, ios::app);
	upisiLicniPosao << noviPosao.getIdPosao() << " ";
	upisiLicniPosao << noviPosao.getAgent().getIme() << " ";
	upisiLicniPosao << noviPosao.getAgent().getPrezime() << " ";
	upisiLicniPosao << noviPosao.getAgent().getUsername() << " ";
	upisiLicniPosao << noviPosao.getTipPosla() << " ";
	//upisiLicniPosao << noviPosao.getFirma().getLokacija() << " ";
//	upisiLicniPosao << noviPosao.getFirma().getPlataUposlenika() << " ";
	upisiLicniPosao << noviPosao.getFirma().getLokacija() << " ";
	upisiLicniPosao << noviPosao.getZavrsen() << endl;
	upisiLicniPosao.close();

	//Upisivanje u globalnu datoteku "poslovi.txt"
	ofstream upisiGlobalniPosao("poslovi.txt", ios::app);
	upisiGlobalniPosao << noviPosao.getIdPosao() << " ";
	upisiGlobalniPosao << noviPosao.getAgent().getIme() << " ";
	upisiGlobalniPosao << noviPosao.getAgent().getPrezime() << " ";
	upisiGlobalniPosao << noviPosao.getAgent().getUsername() << " ";
	upisiGlobalniPosao << noviPosao.getTipPosla() << " ";
	//upisiGlobalniPosao << noviPosao.getFirma().getLokacija() << " ";
	//upisiGlobalniPosao << noviPosao.getFirma().getPlataUposlenika() << " ";
	upisiGlobalniPosao << noviPosao.getFirma().getLokacija() << " ";
	upisiGlobalniPosao << noviPosao.getZavrsen() << endl;
	upisiGlobalniPosao.close();

	cout << "\n\t\t="; Sleep(100); cout << "="; Sleep(100); cout << "="; Sleep(100); cout << "=";
	Sleep(100); cout << "="; Sleep(100); cout << " Posao uspjesno dodan!\n";
	Sleep(1500);
	system("cls");
}

void unosOsobe() {
	system("cls");

	cout << "\n\n\n\n";
	cout << crt << "\t\t\t\t::UNOS NOVE OSOBE::" << crt;

	//Unos imena i prezimena
	cout << "\n\n\t\t\tUnesite ime osobe: ";
	string ime;
	getline(cin, ime);
	nizOsoba[brojOsoba].setIme(ime.c_str());

	cin.ignore();

	cout << "\t\t\tUnesite prezime: ";
	string prezime;
	getline(cin, prezime);
	nizOsoba[brojOsoba].setPrezime(prezime.c_str());
	cin.ignore();

	//Unos username
	
	string username;
	//const char* un{};
	cout << "\t\t\tUnesite username: ";
	getline(cin, username);
	//nizOsoba[brojOsoba].setUsername(un);
	cin.ignore();

	//Unos passworda
	string password;

	//do {
	cout << "\t\t\tUnesite password: ";
	getline(cin, password);
	cin.ignore();
	nizOsoba[brojOsoba].setPassword(password.c_str());
	

	//Odabir tipa korisnika
	int odabir;
	cout << "\t\t\tZa koju vrstu osobe se prijavljujete?\n";
	cout << "\t\t\t1. Uposlenik\n";
	cout << "\t\t\t2. Agent\n";

	cout << "\t\t\tOdabir: ";
	do {
		cin >> odabir;
	} while (odabir < 1 || odabir > 2);
	nizOsoba[brojOsoba].setTipOsobe(TipOsobe(odabir));

	//Ukoliko je korisnik odabrao da zeli biti uposlenik
	if (odabir == 1) {
		double plataUposlenika = 0;
		cout << "\t\t\tUnesite pocetnu platu: ";
		cin >> plataUposlenika;
		Uposlenik noviUposlenik(ime.c_str(), prezime.c_str(), username.c_str(), password.c_str(), plataUposlenika);
		upisiUposlenika(noviUposlenik);
		cout << "\n\t\t="; Sleep(100); cout << "="; Sleep(100); cout << "="; Sleep(100); cout << "=";
		Sleep(100); cout << "="; Sleep(100); cout << " Uposlenik uspjesno registrovan!\n";
		Sleep(1500);
	}
	//Ukoliko je korisnik odabrao da zeli biti agent
	else {
		double prihodiFirme;
		cout << "\t\t\tUnesite prihode firme: ";
		cin >> prihodiFirme;
		Agent noviAgent(ime.c_str(), prezime.c_str(), username.c_str(), password.c_str(), prihodiFirme);
		upisiAgenta(noviAgent);
		cout << "\n\t\t="; Sleep(100); cout << "="; Sleep(100); cout << "="; Sleep(100); cout << "=";
		Sleep(100); cout << "="; Sleep(100); cout << " Agent uspjesno registrovan!\n";
		Sleep(1500);
	}

	//Upis prosljedjenog korisnika u datoteku
	upisiOsobu(nizOsoba[brojOsoba]);
}

void dodajPosao(Osoba osoba) {
	Posao noviPosao;
	Firma novaFirma;
	string imeFajla;

	//Ucitavanje svih oglasa iz globalne datoteke "oglasi.txt"
	Posao* nizPoslova = new Posao[20];
	int brojPosla = 0;
	ifstream ucitaj;
	ucitaj.open("poslovi.txt");
	string naziv, opis, lokacija;
	int id, tipPosla, brojUposlenih, zavrsen;
	double plata;

	while (ucitaj >> id >> naziv >> opis >> lokacija >> tipPosla >> brojUposlenih >> zavrsen >> plata) {
		nizPoslova[brojPosla].setIdPosao(id);
		brojPosla++;
	}
	ucitaj.close();

	//unos posla

	int idPosao;
	cout << "\n\n\n\n";
	cout << crt << "\t\t\t\t::UNOS NOVOG POSLA::" << crt;
	bool validId = false;

	do {
		try {
			cout << "\t\t\tUnesite id posla: ";
			cin >> idPosao;
			if (!cin) {
				throw std::runtime_error("Pogresan unos. Unesi novi id.");
			}
			validId = true;
			for (int i = 0; i < brojPosla; i++) {
				if (nizPoslova[i].getIdPosao() == idPosao) {
					validId = false;
					break;
				}
			}
			if (!validId) {
				cout << "\t\t\tId oglasa vec postoji. Molimo unesite novi id.\n";
			}

		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
	} while (!validId);

	noviPosao.setIdPosao(idPosao);

	//Unos tipa oglasa
	noviPosao.setTipPosla();

	//Postavljanje stanja posla na "aktivan"
	noviPosao.setZavrsen(0);

	//Unos firm koja se veze za oglas
	novaFirma.setFirma();

	//Unos plate 
	//noviPosao.setPlata();

	//Postavljanje firme za posao
	noviPosao.setFirma(novaFirma);

	//Postavljanje agenta za posao
	noviPosao.setAgent(osoba);

	//Upisivanje posla u datotaeku
	upisiPosao(noviPosao, imeFajla);
}

/*
int pregledSvihPoslova(Osoba osoba) {
	//Ucitavanje svih uposlenika (potencijalno buducih)
	vector<Uposlenik> nizUposlenika;
	ifstream ucitaj;
	ucitaj.open("uposlenici.txt");

	string imeUposlenika, prezimeUposlenika, usernameUposlenika, passwordUposlenika;
	double plataUposlenika;

	while (ucitaj >> imeUposlenika >> prezimeUposlenika >> usernameUposlenika >> passwordUposlenika >> plataUposlenika) {
		shared_ptr<Uposlenik> temp = make_shared<Uposlenik>(imeUposlenika.c_str(), prezimeUposlenika.c_str(), usernameUposlenika.c_str(), passwordUposlenika.c_str(), plataUposlenika);
		nizUposlenika.push_back(*temp);
	}

	//Ucitavanje svih dostupnih poslova
	vector<Posao> poslovi;
	ifstream ucitajPosao;
	ucitajPosao.open("poslovi.txt");

	string naziv, opis, lokacija;
	int id, tipPosla, brojUposlenih, zavrsen, plata;

	while (ucitajPosao >> id >> naziv >> opis >> lokacija >> tipPosla >> brojUposlenih >> zavrsen >> plata) {
		shared_ptr<Posao> temp = make_shared<Posao>(id, naziv.c_str(), opis.c_str(), lokacija.c_str(), (TipPosla)tipPosla, brojUposlenih, zavrsen, plata);
		poslovi.push_back(*temp);
	}
	ucitajPosao.close();

	//Ispis poslova
	cout << "\n\n\n\n\n";
	if (poslovi.size() == 0) {
		cout << "\t\t\tNema poslova!";
		return 0;
	}
	else {
		cout << "\t" << setw(7) << left << "|ID" << setw(16) << left << "|naziv" << setw(22) << left << "|opis"
			<< setw(25) << left << "|Username" << setw(16) << left << "|tipPosla" << setw(19) << left << "|brojUposlenih"
			<< setw(16) << left << "|Lokacija" << setw(20) << left << "|zavrsen" << setw(15) << left << "|plata" << "|" << "\n";
		cout << "\t===========================================================================================================================================================================================================\n";
		for (int i = 0; i < poslovi.size(); i++) {
			cout << poslovi[i];
		}
	}
	cout << "\n\n\n";
}

*/

void ucitajOsobe() {
	ifstream ucitaj;
	ucitaj.open("osobe.txt");
	string ime, prezime, username, password;
	int tipOsobe;
	while (ucitaj >> ime >> prezime >> username >> password >> tipOsobe) {
		nizOsoba[brojOsoba].setIme(ime.c_str());
		nizOsoba[brojOsoba].setPrezime(prezime.c_str());
		nizOsoba[brojOsoba].setUsername(username.c_str());
		nizOsoba[brojOsoba].setPassword(password.c_str());
		nizOsoba[brojOsoba].setTipOsobe(tipOsobe);
		brojOsoba++;
	}
	ucitaj.close();
}


//Funkcija koja azurira stanje posla iz "aktivno" u "zavrseno" u globalnoj datoteci svih poslova ("poslovi.txt")
void azurirajPoslove(int idPosao) {
	//Ucitavanje svih poslova
	Posao* poslovi = new Posao[50];
	int brojPoslova = 0;
	ifstream ucitajPoslove;
	ucitajPoslove.open("poslovi.txt");

	string naziv, opis, lokacija;
	//int id, tipPosla, brojUposlenih, zavrsen, plata;

	/*while (ucitajPoslove >> id >> naziv >> opis >> lokacija >> tipPosla >> brojUposlenih >> zavrsen >> plata) {
		poslovi[brojPoslova] = Posao(id, naziv.c_str(), opis.c_str(), lokacija.c_str(), (TipPosla)tipPosla, brojUposlenih, zavrsen, plata);
		brojPoslova++;
	}
	*/

	//Pronalazenje posla i mijenjanje njegovog stanja
	for (int i = 0; i < brojPoslova; i++) {
		if (poslovi[i].getIdPosao() == idPosao) {
			poslovi[i].promijeniStanje();
		}
	}

	//azuriranje poslova iz datoteke "poslovi.txt"
	ofstream azurirajPoslove("poslovi.txt", ios::trunc);
	for (int i = 0; i < brojPoslova; i++) {
		azurirajPoslove << poslovi[i].getIdPosao() << " ";
		azurirajPoslove << poslovi[i].getAgent().getIme() << " ";
		azurirajPoslove << poslovi[i].getAgent().getPrezime() << " ";
		azurirajPoslove << poslovi[i].getAgent().getUsername() << " ";
		azurirajPoslove << poslovi[i].getTipPosla() << " ";
		azurirajPoslove << poslovi[i].getFirma().getNaziv() << " ";
		azurirajPoslove << poslovi[i].getPlata() << " ";
		azurirajPoslove << poslovi[i].getFirma().getBrojUposlenih() << " ";
		azurirajPoslove << poslovi[i].getFirma().getLokacija() << " ";
		azurirajPoslove << poslovi[i].getZavrsen() << endl;
	}
	azurirajPoslove.close();
}

//Funkcija koja azurira stanje posla iz "aktivno" u "zavrseno" 
void azurirajPosloveAgenta(int idOglasa, char* usernameAgenta) {
	//Formiranje imena datoteke u kojoj se nalaze poslovi agenta
	string imeFajla;
	for (int i = 0; i < strlen(usernameAgenta); i++) {
		imeFajla += usernameAgenta[i];
	}
	imeFajla += "-poslovi.txt";

	//Ucitavanje poslova iz navedene datoteke
	Posao* posloviAgenta = new Posao[50];
	int brojPoslova = 0;
	ifstream ucitajPoslove;
	ucitajPoslove.open(imeFajla);

	string naziv, opis, lokacija;
	//int id, tipPosla, brojUposlenih, zavrsen, plata;

	/*while (ucitajPoslove >> id >> naziv >> opis >> lokacija >> tipPosla >> brojUposlenih >> zavrsen >> plata) {
		posloviAgenta[brojPoslova] = Posao(id, naziv.c_str(), opis.c_str(), lokacija.c_str(), (TipPosla)tipPosla, brojUposlenih, zavrsen, plata);
		brojPoslova++;
	}
	*/

	//Pronalazenje trazenog posla i mijenjanje njegovog stanja
	for (int i = 0; i < brojPoslova; i++) {
		if (posloviAgenta[i].getIdPosao() == idOglasa) {
			posloviAgenta[i].promijeniStanje();
		}
	}

	//auriranje iz navedene datoteke
	ofstream azurirajPoslove(imeFajla, ios::trunc);
	for (int i = 0; i < brojPoslova; i++) {
		azurirajPoslove << posloviAgenta[i].getIdPosao() << " ";
		azurirajPoslove << posloviAgenta[i].getAgent().getIme() << " ";
		azurirajPoslove << posloviAgenta[i].getAgent().getPrezime() << " ";
		azurirajPoslove << posloviAgenta[i].getAgent().getUsername() << " ";
		azurirajPoslove << posloviAgenta[i].getTipPosla() << " ";
		azurirajPoslove << posloviAgenta[i].getFirma().getNaziv() << " ";
		//azurirajPoslove << posloviAgenta[i].getFirma().getPlata() << " ";
		azurirajPoslove << posloviAgenta[i].getFirma().getBrojUposlenih() << " ";
		azurirajPoslove << posloviAgenta[i].getFirma().getLokacija() << " ";
		//azurirajPoslove << posloviAgenta[i].getFirma().get() << " ";
		azurirajPoslove << posloviAgenta[i].getZavrsen() << endl;
	}
	azurirajPoslove.close();
}

int main() {
	//Ucitavanje svih osobaa u globalni niz u fajlu "FunkcijeZaManipulacijuFajlovima.h"
	ucitajOsobe();

	//Varijabla za odabir panela u glavnom meniju
	//char odabir;

	system("cls");
	do {
		//Definisanje osobaa koji se treba prijaviti
		Osoba osoba;
		char* username = new char[30];
		char* password = new char[20];
		system("cls");
	//LOGIN:
		char odabir = loginMeni();

		if ((int)odabir == 3) {	//Opcija 3: Izlaz
			break;
		}
		else if ((int)odabir == 1) {	//Opcija 1: Login
			system("cls");

			if (osoba.getTipOsobe() == (TipOsobe)0) {
				system("cls");
				//Varijabla za odabir panela u Uposlenik meniju
				char izbor = 0;
				do {
					if ((int)izbor == 1) {		//Opcija 1: Pregled Posla
						system("cls");
					//	int izbor = pregledSvihPoslova(osoba);
					}
					system("PAUSE");
					system("cls");
				} while (1);
			}
			else {
				system("cls");
				//Varijabla za odabir panela u Agent meniju
				char izbor;
				do {
					izbor = agentMeni(osoba);
					if ((int)izbor == 4) {		//Opcija 4: Prekid Agent menija
						break;
					}
					
					if ((int)izbor == 1) {		//Opcija 1: Dodavanje novog Posla
						system("cls");
						dodajPosao(osoba);
					}

					system("PAUSE");
					system("cls");
				} while (1);
			}
		}
		else if ((int)odabir == 2) {	//Opcija 2: Registracija
			system("cls");
			unosOsobe();
		}
	} while (1);
	return 0;
}