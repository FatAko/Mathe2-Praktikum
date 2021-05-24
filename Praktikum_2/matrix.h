#pragma once
#include <vector>
#include "vektor.h";

class CMyMatrix
{
public:
	CMyMatrix();
	~CMyMatrix();

	void setMatrix(int x, int y);
	double getComponent(int x, int y);
	void setComponent(int x, int y, double value);
	CMyMatrix invers();
	int getAnzahlZeilen();
	int getAnzahlSpalten();
	CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));
	CMyVektor newton(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));
private:
	std::vector<CMyVektor*> matrix;
};
CMyVektor operator*(CMyMatrix A, CMyVektor x);
CMyVektor fMatrix(CMyVektor pVektor);
CMyVektor fNewton(CMyVektor pVektor);