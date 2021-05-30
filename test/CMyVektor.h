#pragma once
#include <vector>
#include<string>
using namespace std;
class CMyVektor{
private: 
	int dimension;
	vector<double>komponenten;
public:
	CMyVektor(int pDimension);
	int getDimension();
	double getKomponente(int pStelle);
	void setKomponente(int pStelle,double pNeu);
	double laengeVektor(); 
	friend CMyVektor operator+(CMyVektor a, CMyVektor b);
	friend CMyVektor operator*(double lambda, CMyVektor a);
	CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x));
	CMyVektor gradientverfahren(CMyVektor x, double (*funktion)(CMyVektor x),double lambda = 1.0);
	string ausgabe(CMyVektor x, string art);
};
double fgrad(CMyVektor pX);
double gverfahren(CMyVektor pX);
