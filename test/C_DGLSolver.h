#pragma once
#include "CMyVektor.h"
class C_DGLSolver {
private:
	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double (*f_DGL_nterOrdnung)(CMyVektor y, double x);
	CMyVektor ableitungen(CMyVektor y, double x);
	bool nOrdnung ;
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) :nOrdnung{ false }, f_DGL_System{ f_DGL_System }{};
	C_DGLSolver (double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) :nOrdnung{ true }, f_DGL_nterOrdnung{ f_DGL_nterOrdnung }{};
	CMyVektor euler_verfahren(double x_start, double x_end, int schritte, CMyVektor y_start);
	CMyVektor heun_verfahren(double x_start, double x_end, int schritte, CMyVektor y_start);
};