// Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utilities.h"
#include <iostream>

using namespace std;

int CreateMask(int i, int j)
{
	const int len = sizeof(int) * 8;
	unsigned int base = 0; // 00000000
	base = ~base; // 11111111

	unsigned int highBits = base;
	unsigned int lowBits = base;

	highBits = highBits >> (i+1); // 
	highBits = highBits << (i+1); // 

	lowBits = lowBits << (len - j);
	lowBits = lowBits >> (len - j);

	unsigned int mask = highBits | lowBits;

	unsigned int bits[len];
	UtilitiesNS::Utilities::ToBinary(mask, bits);
	UtilitiesNS::Utilities::ShowBinary(bits, len);
	return mask;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int mask = CreateMask(3, 2);
	int n = 20;
	int m = 3;
	m = m << 2;

	n = n & mask;
	n = n | m;
	cout << endl << n << endl;
	return 0;
}

