#include "C_DGLSolver.h"
#include "vektor.h"

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
		/*
		  für den Fall, dass eine Funktion für ein DGL-System übergeben wurde, diese Funk-
		  tion an der Stelle (y; x) auswerten, 
		*/
		result = f_DGL_System(y,x);
		return result;
	}
		/*
		 fur den Fall, dass eine Funktion für eine DGL höherer Ordnung übergeben wurde,
		 eine Transformation in ein DGL-System durchführt und dazu die rechte Seite eines
		 entsprechenden Systems ausgibt (vgl. Skript, S. 19).
		*/
	else
	{
		for (int i = 0; i < y.getDimension()-1; i++)
		{
			result.setComponent(i,y.getComponent(i+1));
		}
		result.setComponent(y.getDimension() - 1, f_DGL_nterOrdnung(y, x));
		return result;
	}
}

void C_DGLSolver::euler(double xstart, double xend, int anzahlSchritte, CMyVektor y_start) {
	double h = (xend - xstart) / anzahlSchritte;
	double start = xstart, ende = xend;
	for (int i = 0; i < anzahlSchritte; i++)
	{

	}
	
}