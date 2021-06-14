#define _USE_MATH_DEFINES
#include "CKomplex.h"
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;
CKomplex::CKomplex() {}
CKomplex::~CKomplex() {}

CKomplex::CKomplex(double a, double b) {
	realteil = a;
	imaginaerteil = b;
}
CKomplex::CKomplex(double phi) {
	//this->phi = phi;
	this->realteil = cos(phi);
	this->imaginaerteil = sin(phi);
}
double CKomplex::re() {
	return realteil;
}
double CKomplex::im() {
	return imaginaerteil;
}
CKomplex operator+(CKomplex a, CKomplex b) {
	CKomplex result(a.realteil + b.realteil, a.imaginaerteil + b.imaginaerteil);
	return result;
}
CKomplex operator* (CKomplex a, CKomplex b) {
	CKomplex result((a.realteil * b.realteil) - (a.imaginaerteil * b.imaginaerteil), (a.realteil * b.imaginaerteil) + (b.realteil * a.imaginaerteil));
	return result;
}

CKomplex operator*(double a, CKomplex b) {
	CKomplex result(a * b.realteil, a * b.imaginaerteil);
	return result;
}
double CKomplex::abs() {
	return sqrt((this->realteil * this->realteil) * (this->imaginaerteil * this->imaginaerteil));
}

std::vector<CKomplex>  werte_einlesen(const char* dateiname)
{
	int i, N, idx;
	double re, im;
	std::vector<CKomplex> werte;
	// File oeffnen
	std::ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i < N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char* dateiname, std::vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();
	// File oeffnen
	std::ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << std::endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << std::endl;
	// File schliessen
	fp.close();
}

std::vector<CKomplex> fourier_hintrantransformation(std::vector<CKomplex> daten) {
	std::vector<CKomplex> result;
	result.resize(daten.size());
	int N = daten.size();
	int k = 0;
	for (int n = 0; n < N; n++)
	{
		CKomplex aktuell;
		for (int k = 0; k < N; k++)
		{
			CKomplex e(-1 * (2 * M_PI * k * n) / N);
			aktuell = aktuell + daten.at(k) * e;
		}
		aktuell = (1 / sqrt(N)) * aktuell;
		result.at(n) = aktuell;
	}
	return result;
}

std::vector<CKomplex> fourier_ruecktrantransformation(std::vector<CKomplex> daten) {
	std::vector<CKomplex> result;
	result.resize(daten.size());
	int N = daten.size();
	int k = 0;
	for (int n = 0; n < N; n++)
	{
		CKomplex aktuell;
		for (int k = 0; k < N; k++)
		{
			CKomplex e(1 * (2 * M_PI * k * n) / N);
			aktuell = aktuell + daten.at(k) * e;
		}
		aktuell = (1 / sqrt(N)) * aktuell;
		result.at(n) = aktuell;
	}
	return result;
}

double maxdiff(std::vector<CKomplex> a, std::vector<CKomplex> b)
{
	double result = 0.0, tmp = 0.0;
	for (int i = 0; i < a.size(); i++) {
		tmp = (a[i] + ((-1) * b[i])).abs();
		if (tmp > result)
			result = tmp;
	}
	return result;
}