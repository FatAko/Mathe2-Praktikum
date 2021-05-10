#include <iostream>
#include "matrix.h"
#include "vektor.h"

using namespace std;

int main() {
	CMyVektor x;
	x.makeVektor(4);
	x.setComponent(0, 1);
	x.setComponent(1, 2);
	x.setComponent(2, 0);
	x.setComponent(3, 3);
	CMyMatrix jb = jb.jacobi(x, fMatrix);
	system("PAUSE");
	return 0;
}