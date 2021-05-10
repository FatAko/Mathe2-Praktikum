#include <iostream>
#include "vektor.h"
using namespace std;

int main() {
	CMyVektor vektor1, vektor2;
	vektor1.makeVektor(2);
	vektor2.makeVektor(3);
	vektor1.setComponent(0, 0.2); vektor1.setComponent(1, -2.1);
	vektor2.setComponent(0, 0); vektor2.setComponent(1, 0); vektor2.setComponent(2, 0);
	cout << "f = 1 , g = 0" << endl;
	int eingabe = 0;
	cin >> eingabe;
	if (eingabe)
	{
		gradientenVerfahren(vektor1, f);
	}
	else
	{
		gradientenVerfahren(vektor2, g, 0.1);
	}
	system("PAUSE");
	return 0;
}