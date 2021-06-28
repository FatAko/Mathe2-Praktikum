#pragma once
#include <vector>

class CLotto
{
public:
	CLotto();
	CLotto(int k, int n, int s);
	~CLotto();

	void tippzettel_setzen();
	std::vector<int> kausNLottoZiehung();
	std::vector<int> kausNLottoRichtig();

private:
	std::vector<int> tippzettel;
	std::vector<int> ziehung;
	int k = 0, n = 0, s = 0;

};


