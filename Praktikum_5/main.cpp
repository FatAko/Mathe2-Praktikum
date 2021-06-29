#include <iostream>
#include "CZufall.h";
#include "CLotto.h"
using namespace std;

int main() {
	//Aufgabe 1 a)
	/*CZufall aufgabe1;
	int s = 0;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
	{
		cout << "Hauefigkeit von " << i << " " << anzahlen.at(i) << endl;
 	}*/

	//Aufgabe 1 b) -> immer gleiche Werte
	/*CZufall aufgabe1;
	int s = 0;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen2.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen3.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen4.at(i) << endl;*/

	//Aufgabe 1 c) -> unterschiedliche Werte
	/*CZufall aufgabe1;
	cout << "s = 0" << endl;
	aufgabe1.initialisiere(0);
	vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
	cout << "----" << endl;
	cout << "s = 1" << endl;
	aufgabe1.initialisiere(1);
	vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen2.at(i) << endl;
	cout << "----" << endl;
	cout << "s = 2" << endl;
	aufgabe1.initialisiere(2);
	vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen3.at(i) << endl;
	cout << "----" << endl;
	cout << "s = 3" << endl;
	aufgabe1.initialisiere(3);
	vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen4.at(i) << endl;*/

	//Aufgabe 1 d) -> immer gleiche Werte
	/*CZufall aufgabe1;
	int s = time(NULL);
	aufgabe1.initialisiere(s);
	vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen2.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen3.at(i) << endl;
	cout << "----" << endl;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen4.at(i) << endl;*/

	//Aufgabe 1 e) -> immer nur eine Zahl aus dem Bereich
	/*CZufall aufgabe1;
	vector<int> anzahlen1 = aufgabe1.test_falsch(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
		cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;*/

	//Aufgabe 2
	/*CLotto aufgabe2(6,49,time(NULL));
	vector<int> ziehung(49, 0);
	vector<int> richtig(49, 0);
	aufgabe2.tippzettel_setzen();
	ziehung = aufgabe2.kausNLottoZiehung();
	cout << "--------------Ziehung--------------" << endl;
	for (int i = 1; i < ziehung.size(); i++)
	{
		cout << i << " : " << " \t" << ziehung.at(i) << endl;
	}
	richtig = aufgabe2.kausNLottoRichtig();
	cout << "--------------Ergebnis--------------" << endl;
	for (int i = 1; i < richtig.size(); i++)
	{
		cout << i << " : " << " \t" << richtig.at(i) << endl;
	}*/

	//Aufgabe 3
	montecarlo(2,5,33,1000000,1);
	montecarlo(2, 5, 33, 1000000, 0);

	system("PAUSE");
	return 0;
}