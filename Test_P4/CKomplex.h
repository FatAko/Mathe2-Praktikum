#pragma once
#include <vector>

class CKomplex
{
public:
	CKomplex(double a, double b);
	CKomplex(double phi);
	CKomplex();
	~CKomplex();

	double re();
	double im();
	double abs();
	friend CKomplex operator+ (CKomplex a, CKomplex b);
	friend CKomplex operator* (CKomplex a, CKomplex b);
	friend CKomplex operator* (double a, CKomplex b);

private:
	double imaginaerteil = 0;
	double realteil = 0;
	double phi = 0;
};

std::vector<CKomplex> werte_einlesen(const char* dateiname);
void werte_ausgeben(const char* dateiname, std::vector<CKomplex> werte, double epsilon = -1.0);

std::vector<CKomplex> fourier_hintrantransformation(std::vector<CKomplex> daten);
std::vector<CKomplex> fourier_ruecktrantransformation(std::vector<CKomplex> daten);

double maxdiff(std::vector<CKomplex> a, std::vector<CKomplex> b);
