#include "matrix.h"
#include "vektor.h"
#include <iostream>

CMyMatrix::CMyMatrix(){}

CMyMatrix::~CMyMatrix(){}

void CMyMatrix::setMatrix(int x, int y) {
	this->matrix.resize(y);
	for (int i = 0; i < y; i++)
	{
		this->matrix.at(i) = new CMyVektor();
		matrix.at(i)->makeVektor(x);
	}
}
double CMyMatrix::getComponent(int x, int y) {
	return this->matrix.at(x)->getComponent(y);
}

void CMyMatrix::setComponent(int x, int y, double value) {
	this->matrix.at(x)->setComponent(y, value);
}

int CMyMatrix::getAnzahlZeilen() {
	return matrix.size();
}
int CMyMatrix::getAnzahlSpalten() {
	return matrix.at(0)->getDimension();
}

CMyMatrix CMyMatrix::invers() {
	if (this->matrix.size() != 2 || this->matrix.at(0)->getDimension() != 2)
	{
		std::cout << "Fehler, da Matrix nicht 2 x 2." << std::endl;
	}
	else
	{
		double vorfaktor = 1 / ((getComponent(0, 0) * getComponent(1, 1)) - (getComponent(0, 1) * getComponent(1, 0)));
		double temp1 = getComponent(0, 0);
		setComponent(0, 0, getComponent(1,1)*vorfaktor);
		setComponent(1, 1, temp1*vorfaktor);
		setComponent(0, 1, getComponent(0, 1) * -1*vorfaktor);
		setComponent(1, 0, getComponent(1, 0) * -1*vorfaktor);
		return *this;
	}
}
CMyVektor operator*(CMyMatrix A, CMyVektor x) {
	double zwischenergebnis = 0;
	CMyVektor result;
	result.makeVektor(x.getDimension());
	int pos = 0;
	for (int i = 0; i < A.getAnzahlSpalten(); i++) //Spalten durchlaufen
	{
		for (int j = 0; j < A.getAnzahlZeilen(); j++) //Zeilen durchlaufen
		{
			zwischenergebnis = zwischenergebnis + A.getComponent(i,j) * x.getComponent(j);
		}
		result.setComponent(pos, zwischenergebnis);
		pos++;
		zwischenergebnis = 0;
	}
	return result;
}

CMyVektor fMatrix(CMyVektor pVektor) {
	CMyVektor vektor;
	vektor.makeVektor(3);
	vektor.setComponent(0, pVektor.getComponent(0) * pVektor.getComponent(1) * exp(pVektor.getComponent(2)));
	vektor.setComponent(1, pVektor.getComponent(1) * pVektor.getComponent(2) * pVektor.getComponent(3));
	vektor.setComponent(2, pVektor.getComponent(3));
	return vektor;
}

CMyVektor gradMatrix(CMyVektor x, double (*funktion)(CMyVektor x)) {
	CMyVektor gradient, temp;
	gradient.makeVektor(x.getDimension());
	for (int i = 0; i < x.getDimension(); i++) {
		temp = x;
		temp.setComponent(i, x.getComponent(i) + pow(10.0, -4.0));
		gradient.setComponent(i, (funktion(temp) - funktion(x)) / pow(10.0, -4.0)); // besser: funktion(x) vor for Block
	} return gradient;
}
CMyMatrix CMyMatrix::jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x)) {
	CMyMatrix result;
	int spalte = 0;
	int anzahlDurchgaenge = funktion(x).getDimension();
	while (spalte < anzahlDurchgaenge)
	{
		CMyVektor* gradient = new CMyVektor(), temp;
		gradient->makeVektor(x.getDimension());
		for (int i = 0; i < x.getDimension(); i++) {
			temp = x;
			temp.setComponent(i, x.getComponent(i) + pow(10.0, -4.0));
			gradient->setComponent(i, (funktion(temp).getComponent(spalte) - funktion(x).getComponent(spalte)) / pow(10.0, -4.0)); // besser: funktion(x) vor for Block
		}
		result.matrix.push_back(gradient);
		spalte++;
	}
	return result;
}
