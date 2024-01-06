#pragma once
#include "Firma.h"
using std::string;

enum TipPosla {
	backend = 1, frontend
};



class Posao :
    public Firma
{
private:
	int idPosao;
	int plata;
	char naziv[20], opis[80];
	TipPosla tipRada;
	Firma firma;
	Osoba agent;
	int zavrsen;
public:

	Posao();
	Posao(int id, const char* ime, const char* prezime, const char* username, const char* naziv, int plata, TipPosla tipRada, const char* lokacija, int zavrsen, int brojUposlenih, double prihodiFirme) : agent(ime, prezime, username) , firma(naziv, brojUposlenih, lokacija, plata)
	{
		this->idPosao = id;
		this->tipRada = (TipPosla)tipRada;
		this->zavrsen = zavrsen;

	};
	Posao(int idPosao, TipPosla tipRada, const char* naziv, int plata, int brojUposlenih, const char* lokacija) : Firma(naziv, brojUposlenih, lokacija, plata)
	{
		this->idPosao = idPosao;
		this->tipRada = tipRada;
	};
	Posao(int idPosao, const char* naziv, const char* opis, const char* lokacija, TipPosla tipRada, int brojUposlenih, int plata, int zavrsen) : Firma(naziv, brojUposlenih, lokacija, plata)
	{
	};
	void setIdPosao(int id);
	void setTipPosla();
	void setPlata(int netto);
	void setFirma(Firma firma);
	void setAgent(Osoba agent);
	void setZavrsen(int stanje);
	void promijeniStanje();

	int getIdPosao();
	int getPlata();

	TipPosla getTipPosla();
	Firma getFirma();
	Osoba getAgent();
	int getZavrsen();
	friend Posao operator!(Posao& pos);	// postavlja posao na zavrsen
	friend std::ostream& operator<<(std::ostream& stream, Posao& pos);	// ispisuje 
	
	~Posao();
};

