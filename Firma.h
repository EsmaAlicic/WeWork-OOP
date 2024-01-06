#pragma once
#include "Agent.h"
class Firma :
    public Agent
{
private:
	char naziv[20];
	int brojUposlenih;
	char lokacija[30];
	Agent agent;
public:
	Firma() {};
	Firma(const char* naziv, int brojUposlenih, const char* lokacija, int plata);
	void setNaziv();
	void setBrojUposlenih();
	void setLokacija();
	void setFirma();
	void setAgent(Agent agent);

	char* getNaziv();
	int getBrojUposlenih();
	char* getLokacija();
	Agent getAgent();
	~Firma() {};
};

