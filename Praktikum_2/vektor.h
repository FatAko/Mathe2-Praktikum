#pragma once
#include <vector>

class CMyVektor {
public:
	CMyVektor();
	~CMyVektor();

	//std::vector<double> vektor;
	double getComponent(const int& pos);
	int getDimension();
	void setComponent(const int& pos, const double& value);
	void makeVektor(int dimension);

	double getLength();
private:
	int dimension;
	std::vector<double> vektor;
};

CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x));
CMyVektor operator+(CMyVektor a, CMyVektor b);
CMyVektor operator*(double lambda, CMyVektor a);
CMyVektor gradientenVerfahren(CMyVektor px, double (*funktion)(CMyVektor x), double l = 1.0);
CMyVektor gradientenVerfahren(CMyVektor x, double lambda, double (*funktion)(CMyVektor x));
double f(CMyVektor p);
double g(CMyVektor p);
