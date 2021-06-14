#include <iostream>
#include <vector>
#include "CKomplex.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
	
    vector<CKomplex>original = werte_einlesen("Daten_Original.txt");
    vector<CKomplex> transformiert = fourier_hintrantransformation(original);

    werte_ausgeben("transformiert(-1).txt", transformiert);
    vector<CKomplex> ruecktransformiert1 = fourier_ruecktrantransformation(werte_einlesen("transformiert(-1).txt"));
    cout << "Maximale Abweichung bei Standart-Epsilon: ca. " << maxdiff(original, ruecktransformiert1) << endl;

    werte_ausgeben("transformiert(0.001).txt", transformiert, 0.001);
    vector<CKomplex> ruecktransformiert0001 = fourier_ruecktrantransformation(werte_einlesen("transformiert(0.001).txt"));
    cout << "Maximale Abweichung bei epsilon=0.001: " << maxdiff(original, ruecktransformiert0001) << endl;

    werte_ausgeben("transformiert(0.01).txt", transformiert, 0.01);
    vector<CKomplex> ruecktransformiert001 = fourier_ruecktrantransformation(werte_einlesen("transformiert(0.01).txt"));
    cout << "Maximale Abweichung bei epsilon=0.01: " << maxdiff(original, ruecktransformiert001) << endl;

    werte_ausgeben("transformiert(0.1).txt", transformiert, 0.1);
    vector<CKomplex> ruecktransformiert01 = fourier_ruecktrantransformation(werte_einlesen("transformiert(0.1).txt"));
    cout << "Maximale Abweichung bei epsilon=0.1: " << maxdiff(original, ruecktransformiert01) << endl;

    werte_ausgeben("transformiert(1).txt", transformiert, 1);
    vector<CKomplex> ruecktransformiert = fourier_ruecktrantransformation(werte_einlesen("transformiert(1).txt"));
    cout << "Maximale Abweichung bei epsilon=1: " << maxdiff(original, ruecktransformiert) << endl;

	/*vector<CKomplex>a;
	a.push_back(CKomplex(2, -3));
	a.push_back(CKomplex(1, 3));
	a.push_back(CKomplex(-3, 2));
	a.push_back(CKomplex(1, 0));
	a = fourier_hintrantransformation(a);
	for (int i = 0; i < a.size(); i++)
		cout << a[i].re() << "+j" << a[i].im() << endl;*/

	system("PAUSE");
	return 0;
}