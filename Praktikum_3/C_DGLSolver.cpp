#include "C_DGLSolver.h"
#include "vektor.h"
#include <iostream>

C_DGLSolver::C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) {
	this->höhereOrdnung = false;
	this->f_DGL_System = f_DGL_System;
}
C_DGLSolver::C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) {
	this->höhereOrdnung = true;
	this->f_DGL_nterOrdnung = f_DGL_nterOrdnung;
}


CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x) {
	CMyVektor result;
	result.makeVektor(y.getDimension());
	if (!this->höhereOrdnung)
	{
		result = f_DGL_System(y,x);
		return result;
	}
	else
	{
		for (int i = 0; i < y.getDimension()-1; i++)
		{
			result.setComponent(i,y.getComponent(i+1));
		}
		result.setComponent(y.getDimension()-1, f_DGL_nterOrdnung(y, x));
		return result;
	}
}

void C_DGLSolver::euler(double xstart, double xend, int anzahlSchritte, CMyVektor y_start,bool abweichung) {
	double h = (xend - xstart) / anzahlSchritte;
	double start = xstart, ende = xend;

	int schritt = 0;

	CMyVektor ystart = y_start;
	CMyVektor ableitung = ableitungen(ystart, xstart);

	if (!abweichung)
	{
		std::cout << "h = " << h << std::endl << std::endl;
	}

	while(true)
	{
		if (schritt == anzahlSchritte)
		{
			if (!abweichung)
			{
				std::cout << "Ende bei" << std::endl;
				std::cout << "\t" << "x = " << start << std::endl;
				std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
			}
			break;
		}

		if (!abweichung)
		{
			std::cout << "Schritt " << schritt << ":" << std::endl;
			std::cout << "\t" << "x = " << start << std::endl;
			std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
		}

		ystart = ystart + h * ableitung;

		if (!abweichung)
		{
			std::cout << "\t" << "y' = ( " << ableitung.getComponent(0) << "; " << ableitung.getComponent(1) << ")" << std::endl << std::endl;
		}

		start += h;

		ableitung = ableitungen(ystart, start);

		schritt++;
	}
	if (abweichung)
	{
		std::cout << ystart.getComponent(0) - 0.5;
	}
}

void C_DGLSolver::heun(double xstart, double xend, int anzahlSchritte, CMyVektor y_start,bool abweichung)
{
	double h = (xend - xstart) / anzahlSchritte;

	double start = xstart, ende = xend;

	int schritt = 0;

	CMyVektor ystart = y_start;

	CMyVektor y_Test = ystart;
	CMyVektor y_Mittel = ystart;
	CMyVektor orig_ableitung = ableitungen(ystart, start);
	CMyVektor test_ableitung = ableitungen(ystart, start);

	if (!abweichung)
	{
		std::cout << "h = " << h << std::endl << std::endl << std::endl;
	}

	while(true)
	{
		if(schritt == anzahlSchritte)
		{
			if (!abweichung)
			{
				std::cout << "Ende bei" << std::endl;
				std::cout << "\t" << "x = " << start << std::endl;
				std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
			}
			break;
		}
		
		if (!abweichung)
		{
			std::cout << "Schritt " << schritt << ":" << std::endl;
			std::cout << '\t' << "x = " << start << std::endl;
			std::cout << "\t" << "y = ( " << ystart.getComponent(0) << "; " << ystart.getComponent(1) << ")" << std::endl;
			std::cout << "\t" << "y'_orig = ( " << orig_ableitung.getComponent(0) << "; " << orig_ableitung.getComponent(1) << ")" << std::endl << std::endl;
		}

		y_Test = ystart + h * orig_ableitung; //normaler Rechenschritt ->euler
		test_ableitung = ableitungen(y_Test, start + h);
		y_Mittel = 0.5 * (orig_ableitung + test_ableitung);

		ystart = ystart + h * y_Mittel; //neuer wert berechnen

		if (!abweichung)
		{
			std::cout << "\t" << "y_Test = ( " << y_Test.getComponent(0) << "; " << y_Test.getComponent(1) << ")" << std::endl;
			std::cout << "\t" << "y'_Test = ( " << test_ableitung.getComponent(0) << "; " << test_ableitung.getComponent(1) << ")" << std::endl;
			std::cout << "\t" << "y'_Mittel = ( " << y_Mittel.getComponent(0) << "; " << y_Mittel.getComponent(1) << ")" << std::endl << std::endl;
		}

		start += h; 
		y_Test = ystart;
		orig_ableitung = ableitungen(ystart, start);

		schritt++;
	}
	if (abweichung)
	{
		std::cout << ystart.getComponent(0) - 0.5;
	}
}
