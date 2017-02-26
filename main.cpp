#include<iostream>
#include <cstdlib>
#include "functii.h"

using namespace std;

int main()
{
	char denumire[25],codprodus[10];
	init(denumire,codprodus);
	char ean13[13];
	verif(codprodus,ean13);
	int nean13[13];
	for(int i=0;i<12;i++)
		nean13[i] = ean13[i]-'0';
	cifraCtrl(nean13);
	afisareCod(nean13);
	int b[95];
	generare(b,nean13);
	desen(denumire,nean13,b);
	return 0;
}

