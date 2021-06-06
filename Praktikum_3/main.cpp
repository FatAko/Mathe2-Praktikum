#include "C_DGLSolver.h"
#include "vektor.h"
#include <iostream>

using namespace std;

CMyVektor funk(CMyVektor y, double x) {
	CMyVektor result;
	result.makeVektor(y.getDimension());
	double y1 = y.getComponent(0);
	double y2 = y.getComponent(1);
	result.setComponent(0, 2 * y2 - x * y1);
	result.setComponent(1, y1 * y2 - 2 * pow(x, 3.0));
	return result;
}


double funkN(CMyVektor y, double x) {
	CMyVektor result;
	result.makeVektor(y.getDimension());
	double y0 = y.getComponent(0);
	double y1 = y.getComponent(1);
	double y2 = y.getComponent(2);
	return 2 * x * y1 * y2 + 2 * pow(y0, 2.0) * y1;
}

int main() {
	double start = 0.0, ende = 2.0;
	int schritte = 100;

	C_DGLSolver solver(funk);
	CMyVektor y1;
	y1.makeVektor(2);
	y1.setComponent(0, 0); //y1(0) = 0
	y1.setComponent(1, 1); //y2(0) = 1

	int x = 0, y = 0;
	cout << "Aufgabe 4) (0 : euler und heun) oder (1 : abweichungen mit DGL 3. Ordnung)" << endl;
	cin >> x;
	if (!x)
	{
		cout << "0 = euler , 1 = heun" << endl;
		cin >> y;
		if (!y)
		{
			solver.euler(start, ende, schritte, y1,false);
		}
		else
		{
			solver.heun(start, ende, schritte, y1, false);
		}
	}
	else
	{
		C_DGLSolver solverAbweichung(funkN);
		start = 1;
		CMyVektor y2;
		y2.makeVektor(3);
		y2.setComponent(0, 1);
		y2.setComponent(1, -1);
		y2.setComponent(2, 2);

		cout << "Abweichung bei Euler bei 10 Schritten: "; solverAbweichung.euler(start, ende, 10, y2, true);
		cout << endl;
		cout << "Abweichung bei Heun bei 10 Schritten: "; solverAbweichung.heun(start, ende, 10, y2, true);
		cout << endl;
		cout << "Abweichung bei Euler bei 100 Schritten: "; solverAbweichung.euler(start, ende, 100, y2, true);
		cout << endl;
		cout << "Abweichung bei Heun bei 100 Schritten: "; solverAbweichung.heun(start, ende, 100, y2, true);
		cout << endl;
		cout << "Abweichung bei Euler bei 1000 Schritten: "; solverAbweichung.euler(start, ende, 1000, y2, true);
		cout << endl;
		cout << "Abweichung bei Heun bei 1000 Schritten: "; solverAbweichung.heun(start, ende, 1000, y2, true);
		cout << endl;
		cout << "Abweichung bei Euler bei 10000 Schritten: "; solverAbweichung.euler(start, ende, 10000, y2, true);
		cout << endl;
		cout << "Abweichung bei Heun bei 10000 Schritten: "; solverAbweichung.heun(start, ende, 10000, y2, true);
		cout << endl;
	}
	system("PAUSE");
	return 0;
}
