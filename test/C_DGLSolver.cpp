#include "C_DGLSolver.h"
#include <iostream>
const bool ausgabe=false;

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x) {
	CMyVektor result = y;
	int dimension = y.getDimension();
		double funktionswert=0;
	if(nOrdnung){
		for (int i = 0; i <y.getDimension()-1 ; i++) {
			result.setKomponente(i,y.getKomponente(i+1));
		}

		funktionswert = f_DGL_nterOrdnung(y, x);
		
		result.setKomponente(dimension - 1, funktionswert);
	}
	else
		result = f_DGL_System(y, x);
	return result;
}
CMyVektor C_DGLSolver::euler_verfahren(double x_start, double x_end, int schritte, CMyVektor y_start) {
	double h = (x_end - x_start) / schritte;
	CMyVektor ableitung= ableitungen(y_start, x_start);
	cout << "h = " <<h<< endl << endl << endl;
	for (int i = 0; i < schritte + 1; i++) {
		
			if (i == schritte) {
				if (true) {
					cout << "Ende bei " << endl
						<< '\t' << "x = " << x_start << endl
						<< '\t' << y_start.ausgabe(y_start, "y") << endl;
				}
			}
			else {
				if (true) {
					cout << "Schritt " << i << ":" << endl
						<< '\t' << "x = " << x_start << endl
						<< '\t' << y_start.ausgabe(y_start, "y") << endl;
				}
				y_start = y_start + h * ableitung;
				if (true) 
				cout << '\t' << ableitung.ausgabe(ableitung, "y'") << "" << endl;

				x_start += h;
				ableitung = ableitungen(y_start, x_start);
			}
		}
	
	return y_start;
}
CMyVektor C_DGLSolver::heun_verfahren(double x_start, double x_end, int schritte, CMyVektor y)
{
	double h = (x_end - x_start) / schritte;
	CMyVektor y_Test = y, y_Mittel = y, orig_ableitung=ableitungen(y,x_start),test_ableitung=ableitungen(y,x_start);
	cout << "h = " << h << endl << endl << endl;
	for (int i = 0; i < schritte+1; i++) {
		if (i == schritte ) {
			if (ausgabe) {
				cout << "Ende bei " << endl
					<< '\t' << "x = " << x_start << endl
					<< '\t' << y.ausgabe(y, "y") << endl;
			}
		}
		else {
			if (ausgabe) {

				cout << "Schritt " << i << ":" << endl
					<< '\t' << "x = " << x_start << endl
					<< '\t' << y.ausgabe(y, "y") << endl
					<< '\t' << orig_ableitung.ausgabe(orig_ableitung, "y'_orig") << endl << endl;
			}
			y_Test = y+ h * orig_ableitung; //normaler Rechenschritt ->euler
            test_ableitung = ableitungen(y_Test, x_start+h);
			y_Mittel = 0.5 * (orig_ableitung + test_ableitung);//mittelwert zwischen alten schritt und neuen

			y = y + h * y_Mittel; //neuer wert berechnen
			if (ausgabe) {
				cout << '\t' << y_Test.ausgabe(y, "y_Test") << endl
					<< '\t' << test_ableitung.ausgabe(test_ableitung, "y'_Test") << endl << endl
					<< '\t' << y_Mittel.ausgabe(y_Mittel, "y'_Mittel") << endl << endl;
			}
			x_start += h; //nächster schritt
			y_Test = y; 
			orig_ableitung = ableitungen(y, x_start);
		}
	}
	
	return y;
}

