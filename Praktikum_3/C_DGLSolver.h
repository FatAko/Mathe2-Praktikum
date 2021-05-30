#pragma once
#include "vektor.h"

class C_DGLSolver
{
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x));

	void euler(double xstart, double xend, int anzahlSchritte, CMyVektor y_start);
	void heun(double xstart, double xend, int anzahlSchritte, CMyVektor y_start);
private:
	bool höhereOrdnung = false; //privates Attribut, um zu prüfen, ob ein DGL-System oder eine DGL höherer Ordnung behandelt werden soll
	CMyVektor (*f_DGL_System)(CMyVektor y, double x); //Funktionspointer, die die rechte Seite eines DGL-Systems repräsentiert
	double (*f_DGL_nterOrdnung)(CMyVektor y, double x); //Funktionspointer, die eine DGL höherer Ordnung repräsentiert

	CMyVektor ableitungen(CMyVektor y, double x);
};