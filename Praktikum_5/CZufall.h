#pragma once
#include <vector>

class CZufall
{
public:
	CZufall();
	~CZufall();

	int wert(int a, int b);
	void initialisiere(int s);
	
	std::vector<int> test(int a, int b, int N);
	std::vector<int> test_falsch(int a, int b, int N);
};

