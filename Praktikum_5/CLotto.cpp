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
	if (s < 0)
	{
		this->s = time(NULL);
	}
	else
	{
		this->s = s;
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

std::vector<int> CLotto::kausNLottoZiehung() {
	std::vector<int> ziehung(n+1, 0);
	int wert = 0;
	CZufall zufall;
	zufall.initialisiere(time(NULL));
	for (int i = k; i > 0; i--)
	{
		wert = zufall.wert(1, n);
		ziehung.at(wert) = 1;
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