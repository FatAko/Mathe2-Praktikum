#include "C_DGLSolver.h"
#include <iostream>
using namespace std;
CMyVektor funktionNormal(CMyVektor y,double x){
	CMyVektor result = y;
	double y1 = y.getKomponente(0),y2= y.getKomponente(1),tmp=0.0;
	tmp = 2 * y2 - x * y1;
	result.setKomponente(0, tmp);
	tmp =  y1*y2-2*x*x*x;
	result.setKomponente(1, tmp);
	return result;

}

double funktionNten(CMyVektor y, double x) {
	CMyVektor result = y;
	double y0= y.getKomponente(0) ,y1 = y.getKomponente(1), y2 = y.getKomponente(2),tmp=0.0;
	tmp = ((2 * x * y1 * y2) + (2 * y0 * y0 * y1));
	return tmp;
}

int main() {
	double start = 0.0, ende = 2.0,zehn=0.0,hund=0.0,tau=0.0,zehntau=0.0;
	int schritte = 100;

	//C_DGLSolver c_DGLSolver(funktionNten); //teil 1 
	//CMyVektor y(2);
	//y.setKomponente(0, 0);
	//y.setKomponente(1, 1);
	//c_DGLSolver.euler_verfahren(start, ende, schritte, y);
	//c_DGLSolver.heun_verfahren(start, ende, schritte, y);

	///*
	C_DGLSolver c_DGLSolverNten(funktionNten); //teil 1 
	start = 1;
	CMyVektor y2(3);
	y2.setKomponente(0, 1);
	y2.setKomponente(1, -1);
	y2.setKomponente(2, 2);
	//*/

	///*
	cout<<"Abweichung bei Euler bei 10 Schritten: "<< c_DGLSolverNten.euler_verfahren(start, ende, 10, y2).getKomponente(0)-0.5;
	cout << endl;
	cout<<" Abweichung bei Heun bei 10 Schritten: "<<c_DGLSolverNten.heun_verfahren(start, ende, schritte/10, y2).getKomponente(0) - 0.5;
	cout << endl;
	cout << "Abweichung bei Euler bei 100 Schritten: " << c_DGLSolverNten.euler_verfahren(start, ende, schritte, y2).getKomponente(0) - 0.5;
	cout << endl;
	cout << "Abweichung bei Heun bei 100 Schritten: " << c_DGLSolverNten.heun_verfahren(start, ende, schritte, y2).getKomponente(0) -0.5;
	cout << endl;
	cout << "Abweichung bei Euler bei 1000 Schritten: " << c_DGLSolverNten.euler_verfahren(start, ende, schritte*10, y2).getKomponente(0) - 0.5;
	cout << endl;
	cout << "Abweichung bei Heun bei 1000 Schritten: " << c_DGLSolverNten.heun_verfahren(start, ende, schritte*10, y2).getKomponente(0) - 0.5;
	cout << endl;
	cout << "Abweichung bei Euler bei 10000 Schritten: " << c_DGLSolverNten.euler_verfahren(start, ende, schritte * 100, y2).getKomponente(0) - 0.5;
	cout << endl;
	cout << "Abweichung bei Heun bei 10000 Schritten: " << c_DGLSolverNten.heun_verfahren(start, ende, schritte * 100, y2).getKomponente(0) - 0.5;
	cout << endl;
	//*/
		system("PAUSE");
	return 0;
}

