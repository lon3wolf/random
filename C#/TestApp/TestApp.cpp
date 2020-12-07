// TestApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Utilities.h"
#include <iostream>

using namespace std;
using namespace UtilitiesNS;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 10;
	
	int binarr[sizeof(int) * 8];
	UtilitiesNS::Utilities::ToBinary(i, binarr);
	UtilitiesNS::Utilities::ShowBinary(binarr, sizeof(int) * 8);
	
	std::cin >> i;
	return 0;
	
}