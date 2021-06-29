#include "CLotto.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "CZufall.h"

CLotto::CLotto() {}
CLotto::~CLotto() {}
CLotto::CLotto(int k, int n, int s) {
	this->k = k;
	this->n = n;
	CZufall zufall;
	if (s < 0)
	{
		this->s = time(NULL);
		zufall.initialisiere(time(NULL));
	}
	else
	{
		this->s = s;
		zufall.initialisiere(s);
	}
}
void CLotto::tippzettel_setzen() {
	std::vector<int> tz(n+1,0);
	int eingabe = 0;
	for (int i = k; i > 0; i--)
	{
		std::cout << "Welche Zahl ankreuzen? (noch " << i << " Kreuze)" << std::endl;
		std::cin >> eingabe;
		if (eingabe > n)
		{
			std::cout << "Fehler" << std::endl;
			break;
		}
		else
		{
			tz.at(eingabe) = 1;
		}
	}
	this->tippzettel = tz;
}

void CLotto::tippzettel_setzen(std::vector<int> tippzettel) {
	this->tippzettel = tippzettel;
}



bool contains(int wert, std::vector<int> werte) {
	for (int i = 0; i < werte.size(); i++)
	{
		if (werte.at(i) == wert)
		{
			return true;
		}
	}
	return false;
}

std::vector<int> CLotto::kausNLottoZiehung() {
	std::vector<int> ziehung(n+1, 0);
	std::vector<int> werte;
	int wert = 0;
	int zaehler = 0;
	CZufall zufall;
	while (zaehler < k)
	{
		wert = zufall.wert(1, n);
		if (!contains(wert,werte))
		{
			ziehung.at(wert) = 1;
			werte.push_back(wert);
			zaehler++;
		}
	}
	this->ziehung = ziehung;
	return ziehung;
}

std::vector<int> CLotto::kausNLottoRichtig() {
	std::vector<int> richtig(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		if (this->tippzettel.at(i) ==1 && this->ziehung.at(i) == 1)
		{
			richtig.at(i) = 1;
		}
	}
	return richtig;
}

void montecarlo(int r, int k, int n, double N, bool typ) {
	if (typ)
	{
		CLotto spieler1(k,n,1);
		spieler1.tippzettel_setzen(spieler1.kausNLottoZiehung());
		std::vector<int> ziehung;
		std::vector<int> richtig;
		int anazahlrichtig = 0;
		double r_richtig = 0.0;
		for (int i = 0; i < N; i++)
		{
			ziehung = spieler1.kausNLottoZiehung();
			richtig = spieler1.kausNLottoRichtig();
			anazahlrichtig = 0;
			for (int i = 0; i < n; i++)
			{
				if (richtig.at(i) == 1)
				{
					anazahlrichtig++;
				}
			}
			if (anazahlrichtig == r)
			{
				r_richtig++;
			}
		}
		double p = (r_richtig / N);
		p = p * 100;
		std::cout << "Spieler1: Die Wahrscheinlichkeit betraegt: " << p << "% bei n="<< n << " k= " << k << std::endl;
	}
	else
	{
		CLotto spieler2(k, n, time(NULL));
		std::vector<int> ziehung;
		std::vector<int> richtig;
		std::vector<int> tippzettel;
		int anazahlrichtig = 0;
		double r_richtig = 0.0;
		for (int i = 0; i < N; i++)
		{
			spieler2.tippzettel_setzen(spieler2.kausNLottoZiehung());
			ziehung = spieler2.kausNLottoZiehung();
			richtig = spieler2.kausNLottoRichtig();
			anazahlrichtig = 0;
			for (int i = 0; i < n; i++)
			{
				if (richtig.at(i) == 1)
				{
					anazahlrichtig++;
				}
			}
			if (anazahlrichtig == r)
			{
				r_richtig++;
			}
		}
		double p = (r_richtig / N);
		p = p * 100;
		std::cout << "Spieler2: Die Wahrscheinlichkeit betraegt: " << p << "% bei n=" << n << " k= " << k << std::endl;
	}
}