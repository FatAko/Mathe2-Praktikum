#include "CMyVektor.h"
#include <vector>
#include <iostream>
#include<string>
using namespace std;
const double h = 1e-8; //pow vermeiden 1e-8
CMyVektor::CMyVektor(int pDimension) 
{ 
	dimension = pDimension;
	komponenten.resize(pDimension,0);
	
}
int CMyVektor::getDimension() 
{ 
	return dimension; 
}
double CMyVektor::getKomponente(int pStelle) 
{ 
	return komponenten.at(pStelle); 
}
void CMyVektor::setKomponente(int pStelle, double pNeu) 
{
	komponenten.at(pStelle) = pNeu;
}
double CMyVektor::laengeVektor() 
{ 
	double betrag = 0.0;
	for (int i = 0; i < komponenten.size(); i++) {
		betrag += pow(getKomponente(i), 2); //pow vermieden
	}
	return sqrt(betrag);
}
CMyVektor operator+(CMyVektor a, CMyVektor b) {
	if (a.komponenten.size() == b.komponenten.size()) {
		for (int i = 0; i < a.komponenten.size(); i++) {
			a.setKomponente(i,a.getKomponente(i) + b.getKomponente(i)) ;
		}
	}
	else return NULL;
	return a;
}
CMyVektor operator*(double lambda, CMyVektor a) {
	for (int i = 0; i < a.komponenten.size(); i++) {
		a.setKomponente(i, a.getKomponente(i) * lambda); 
	}
	return a;
}
CMyVektor CMyVektor::gradient(CMyVektor x, double (*funktion)(CMyVektor x)) { // ergebnis vektor 
	CMyVektor hvekt = x, result=x;
	double f_von_x = funktion(x);
	for (int i = 0; i <x.komponenten.size(); i++) {
		hvekt.setKomponente(i,hvekt.getKomponente(i) + h);
		result.setKomponente(i,(funktion(hvekt)- f_von_x)/h);
		hvekt.setKomponente(i,x.getKomponente(i) );
	}
	return result;
}
double fgrad(CMyVektor pX) { 
	double x = pX.getKomponente(0); 
	double y= pX.getKomponente(1); 
	
	return (sin(x*y) + sin (x) + cos (y));
} 
CMyVektor CMyVektor::gradientverfahren(CMyVektor x, double (*funktion)(CMyVektor x), double plambda) {
	CMyVektor x_test = x, x_neu = x, x_akt = x, x_grad = x;
	double lambda = plambda;
	for (int i = 0; i <25 ; i++) {
		
		cout << "Schritt " << i << ":" << endl;
		x_akt = x_neu;
		x_grad =gradient(x_akt, funktion);//grad berechnen
		if (i == 24) {
				cout << "Ende wegen Schrittanzahl =25 bei" << endl
					<< '\t' << ausgabe(x_neu, "x") << endl
					<< '\t' << "lambda = " << lambda << endl
					<< '\t' << "f(x) = " << funktion(x) << endl
					<< '\t' << ausgabe(x_grad, "grad f(x)") << endl
					<< '\t' << "||grad f(x) || = " << x_grad.laengeVektor() << endl;
				break;
			}																				
		if (x_grad.laengeVektor() < 1e-5) {
			cout << "Ende wegen ||grad f(x)||<1e-5 bei " << endl
				<< '\t' << ausgabe(x_neu, "x") << endl
				<< '\t' << "lambda = " << lambda << endl
				<< '\t' << "f(x) = " << funktion(x_neu) << endl
				<< '\t' << ausgabe(x_grad, "grad f(x)") << endl
				<< '\t' << "||grad f(x) || = " << x_grad.laengeVektor() << endl;
			break;
		}
		
			x_neu=x_neu+lambda*x_grad;		//neue Werte xneu
		

		cout << '\t' << ausgabe(x_akt, "x") << endl
			<< '\t' << "lambda = " << lambda << endl
			<< '\t' << "f(x) = " << funktion(x_akt) << endl
			<< '\t' << ausgabe(x_grad, "grad f(x)") << endl
			<< '\t' << "||grad f(x)|| = " << x_grad.laengeVektor() << endl<<endl
			<< '\t' << ausgabe(x_neu, "x_neu") << endl
			<< '\t' << "f(x_neu) = " << funktion(x_neu)<<endl<<endl;

		if (funktion(x_neu) > funktion(x_akt)) {																			//neue werte grösser als alte werte
			
			//x_grad= gradient(x_akt, funktion);
			x_test = x_akt + (lambda*2) * x_grad; //test schritt
			
			cout << '\t' << "Test mit doppelter Schrittweite (lambda = " << lambda << "):" << endl;
			if (funktion(x_neu) > funktion(x_test)) {
					
				cout << '\t' << ausgabe(x_test, "x_test") << endl
					<< '\t' << "f(x_test) = " << funktion(x_test) << endl
					<< '\t' << "behalte alte Schrittweite!" << endl<<endl;
			}												
			else {																				//lambda halbieren weil test kleiner geworden ist
				cout << '\t' << ausgabe(x_test, "x_test") << endl
					<< '\t' << "f(x_test) = " << funktion(x_test) << endl
					<< '\t' << "verdoppele Schrittweite!" << endl << endl;
				lambda *= 2;
				x_neu = x_test;
			} 																					
		}	
		else {																										//halbieren von lambda
			do {
				lambda *= 0.5;
				cout << '\t' << "halbierte Schrittweite (lambda = " << lambda << "):" << endl;
				x_neu = x_akt + lambda * x_grad;
				
				cout << '\t' << ausgabe(x_neu, "x_neu") << endl
					<< '\t' << "f(x_neu) = " << funktion(x_neu) << endl << endl;
		
				
			} while (funktion(x_neu) < funktion(x_akt));
			
		}
		
	}
		
		
  return x_neu;
}
double gverfahren(CMyVektor pX) {
	double x = pX.getKomponente(0);
	double y = pX.getKomponente(1);
	double z = pX.getKomponente(2);
	return (-(2*pow(x,2)-2*x*y+pow(y,2)+pow(z,2)-2*x-4*z));
}
string CMyVektor::ausgabe(CMyVektor x,string art) {
	string hilfe = "", ausgabe = art + " = ( ";
	for (int i = 0; i < x.komponenten.size() -1; i++) {
		hilfe = to_string((x.getKomponente(i)));
		ausgabe += hilfe + "; ";
	}
	hilfe = to_string(x.getKomponente(x.komponenten.size()-1));
	ausgabe += hilfe + ")";
	return ausgabe ;
}