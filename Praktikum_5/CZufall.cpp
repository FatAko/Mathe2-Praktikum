#include "CZufall.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

CZufall::CZufall() {}
CZufall::~CZufall() {}

int CZufall::wert(int a, int b) {
	return (rand() % (b-a+1)) + a;
}

void CZufall::initialisiere(int s) {
	srand(s);
}

std::vector<int> CZufall::test(int a, int b, int N) {
	std::vector<int> werte;
	std::vector<int> haeufigkeiten(N,0);

	for (int i = 0; i < N; i++)
	{
		werte.push_back(wert(a,b));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (werte.at(j) == i)
			{
				haeufigkeiten.at(i)++;
			}
		}
	}
	return haeufigkeiten;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N) {
	std::vector<int> werte;
	std::vector<int> haeufigkeiten(N, 0);

	for (int i = 0; i < N; i++)
	{
		initialisiere(time(NULL));
		werte.push_back(wert(a, b));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (werte.at(j) == i)
			{
				haeufigkeiten.at(i)++;
			}
		}
	}
	return haeufigkeiten;
}