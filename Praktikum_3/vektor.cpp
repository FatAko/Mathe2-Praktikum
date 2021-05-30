#include "vektor.h"
#include <iostream>
#include <iomanip>
#include <cmath>
CMyVektor::CMyVektor() {}
CMyVektor::~CMyVektor() {}

double CMyVektor::getLength() {
	double length = 0;
	for (int i = 0; i < vektor.size(); i++)
		length += pow(vektor.at(i), 2);
	return sqrt(length);
}
int CMyVektor::getDimension() {
	return this->dimension;
}
double CMyVektor::getComponent(const int& pos) {
	return this->vektor.at(pos);
}
void CMyVektor::setComponent(const int& pos, const double& value) {
	this->vektor.at(pos) = value;
}
void CMyVektor::makeVektor(int dimension) {
	this->vektor.resize(dimension);
	this->dimension = dimension;
}

CMyVektor operator+(CMyVektor a, CMyVektor b) {
	CMyVektor result;
	if (a.getDimension() == b.getDimension()) {
		result.makeVektor(a.getDimension());
		for (int i = 0; i < result.getDimension(); i++)
			result.setComponent(i, a.getComponent(i) + b.getComponent(i));
	}return result;
}

CMyVektor operator*(double lambda, CMyVektor a) {
	for (int i = 0; i < a.getDimension(); i++)
		a.setComponent(i, a.getComponent(i) * lambda);
	return a;
}

CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x)) {
	CMyVektor gradient, temp;
	gradient.makeVektor(x.getDimension());
	for (int i = 0; i < x.getDimension(); i++) {
		temp = x;
		temp.setComponent(i, x.getComponent(i) + pow(10.0, -8.0));
		gradient.setComponent(i, (funktion(temp) - funktion(x)) / pow(10.0, -8.0)); // besser: funktion(x) vor for Block
	} return gradient;
}

double betrag(CMyVektor x) {
	double m = 0.0;
	for (int i = 0; i < x.getDimension(); i++)
		m += pow(x.getComponent(i), 2.0);
	return sqrt(m);
}

double f(CMyVektor p) {
	double x = p.getComponent(0);
	double y = p.getComponent(1);
	return sin(x * y) + sin(x) + cos(y);
}
double g(CMyVektor p) {
	double x1 = p.getComponent(0);
	double x2 = p.getComponent(1);
	double x3 = p.getComponent(2);
	return -(2 * pow(x1, 2.0) - 2 * x1 * x2 + pow(x2, 2.0) + pow(x3, 2.0) - 2 * x1 - 4 * x3);
}

CMyVektor gradientenVerfahren(CMyVektor x, double lambda, double (*funktion)(CMyVektor x)) {
	CMyVektor x_neu;
	x_neu.makeVektor(x.getDimension());
	x_neu = x + lambda * gradient(x, funktion);
	return x_neu;
}

CMyVektor gradientenVerfahren(CMyVektor px, double (*funktion)(CMyVektor x), double l) {
	int schritt = 0;
	double lambda = l, fx = 0.0, laenge = 0.0, xneu = 0.0, fxneu = 0.0, fxtest = 0.0;
	CMyVektor x = px;
	CMyVektor gradfx; gradfx.makeVektor(px.getDimension());
	CMyVektor x_neu; x_neu.makeVektor(px.getDimension());
	CMyVektor x_test; x_test.makeVektor(px.getDimension());

	while (true) {
		fx = funktion(x);
		gradfx = gradient(x, funktion);
		laenge = betrag(gradfx);
		//Ausgabe Ende 
		if (laenge < pow(10.0, -5.0))
		{
			std::cout << "Ende wegen ||grad f(x)||<1e-5 bei" << std::endl;
			std::cout << std::setw(15) << "x = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << x.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(18) << "lambda = " << lambda << std::endl;
			std::cout << std::setw(16) << "f(x) = " << fx << std::endl;
			std::cout << std::setw(23) << "grad f(x) = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << gradfx.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(25) << "||grad f(x)|| = " << laenge << std::endl;
			std::cout << std::endl;
			break;
		}
		if (schritt == 25)
		{
			std::cout << "Ende wegen Schrittzahl = 25 bei" << std::endl;
			std::cout << std::setw(15) << "x = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << x.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(18) << "lambda = " << lambda << std::endl;
			std::cout << std::setw(16) << "f(x) = " << fx << std::endl;
			std::cout << std::setw(23) << "grad f(x) = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << gradfx.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(25) << "||grad f(x)|| = " << laenge << std::endl;
			std::cout << std::endl;
			break;
		}
		x_neu = gradientenVerfahren(x, lambda, funktion);
		fxneu = funktion(x_neu);
		//Ausgabe: x, lambda, f(x), grad f(x), ||grad f(x)||, x_neu, f(x_neu)
		{
			std::cout << "Schritt " << schritt << ":" << std::endl;
			std::cout << std::setw(15) << "x = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << x.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(18) << "lambda = " << lambda << std::endl;
			std::cout << std::setw(16) << "f(x) = " << fx << std::endl;
			std::cout << std::setw(23) << "grad f(x) = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << gradfx.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(25) << "||grad f(x)|| = " << laenge << std::endl;
			std::cout << std::endl;
			std::cout << std::setw(19) << "x_neu = ( ";
			for (int i = 0; i < x.getDimension(); i++) {
				std::cout << std::fixed << std::setprecision(6) << x_neu.getComponent(i);
				std::cout << std::resetiosflags(std::ios::fixed);
				if (i == x.getDimension() - 1) {
					std::cout << ")" << std::endl;
				}
				else {
					std::cout << "; ";
				}
			}
			std::cout << std::setw(20) << "f(x_neu) = " << fxneu << std::endl;
			std::cout << std::endl;
		}
		if (fxneu > fx) {  //verdoppeln
			lambda = lambda * 2;
			x_test = gradientenVerfahren(x, lambda, funktion);
			fxtest = funktion(x_test);
			//Ausgabe: Test mit doppelter Schrittweite, x_test, f(x_test)
			{
				std::cout << std::setw(51) << "Test mit doppelter Schrittweite (lambda = " << lambda << "):" << std::endl;
				std::cout << std::setw(20) << "x_test = ( ";
				for (int i = 0; i < x.getDimension(); i++) {
					std::cout << std::fixed << std::setprecision(6) << x_test.getComponent(i);
					std::cout << std::resetiosflags(std::ios::fixed);
					if (i == x.getDimension() - 1) {
						std::cout << ")" << std::endl;
					}
					else {
						std::cout << "; ";
					}
				}
				std::cout << std::setw(21) << "f(x_test) = " << fxtest << std::endl;
			}
			if (fxtest < fxneu) {
				//xneu behalten
				x = x_neu;
				lambda = lambda / 2;
				std::cout << std::setw(35) << "behalte alte Schrittweite!" << std::endl;
				std::cout << std::endl;
			}
			else {
				//test wert behalten
				x = x_test;
				std::cout << std::setw(33) << "verdoppele Schrittweite!" << std::endl;
				std::cout << std::endl;
			}
		}
		if (fxneu <= fx) { //halbieren
			while (true) {
				//"halbiere schrittweite"
				lambda = lambda / 2;
				//x_neu = x + lambda * gradfx;
				x_neu = gradientenVerfahren(x, lambda, funktion);
				fxneu = funktion(x_neu);
				//Ausgabe: halbiere Schrittweite, x_neu, f(x_neu)
				{
					std::cout << std::setw(41) << "halbiere Schrittweite (lambda = " << lambda << "):" << std::endl;
					std::cout << std::setw(19) << "x_neu = ( ";
					for (int i = 0; i < x.getDimension(); i++) {
						std::cout << std::fixed << std::setprecision(6) << x_neu.getComponent(i);
						std::cout << std::resetiosflags(std::ios::fixed);
						if (i == x.getDimension() - 1) {
							std::cout << ")" << std::endl;
						}
						else {
							std::cout << "; ";
						}
					}
					std::cout << std::setw(20) << "f(x_neu) = " << fxneu << std::endl;
					std::cout << std::endl;
				}
				if (fxneu > fx) {
					x = x_neu;
					fx = fxneu;
					break;
				}
			}
		}schritt++;
	}
	return x;
}
