// ONP.cpp : Odwrócona notacja polska
// Jakub Porębski 2018

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
	int p = 0;      
	double v1, v2, S[50];
	string element;                   
	stringstream stream;     

	while (true) 
	{
		getline(cin, element);

		if (element == "=") break; 
		stream.clear();         
		stream << element;            

		if (stream >> v1)        					 
			S[p++] = v1;    

		else
		{                   
			v2 = S[--p];      
			v1 = S[--p];
			switch (element[0])     
			{
			case '+': v1 += v2; break;
			case '-': v1 -= v2; break;
			case '*': v1 *= v2; break;
			case '/': v1 /= v2; break;
			}
			S[p++] = v1;      
		}
	}

	cout << fixed << S[--p] << endl;
	cin.get();

	return 0;
}