#include "C_DGLSolver.h"
#include "vektor.h"
#include <iostream>

CMyVektor funk(CMyVektor y, double x) {
	CMyVektor result;
	result.makeVektor(y.getDimension());
	double y1 = y.getComponent(0);
	double y2 = y.getComponent(1);
	result.setComponent(0, 2 * y2 - x + y1);
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
	return 0;
}
