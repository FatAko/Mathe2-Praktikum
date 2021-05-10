#include <iostream>
#include "matrix.h"
#include "vektor.h"

using namespace std;

int main() {
	CMyVektor x;
	CMyMatrix matrix;
	CMyVektor result;
	x.makeVektor(2);
	x.setComponent(0, 1);
	x.setComponent(1, 1);
	result = matrix.newton(x,fNewton);
	system("PAUSE");
	return 0;
}