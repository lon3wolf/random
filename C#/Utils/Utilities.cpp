#include "stdafx.h"
#include "Utilities.h"
#include <iostream>
#include <string>

using namespace std;
namespace UtilitiesNS
{
	Utilities::Utilities()
	{
	}


	Utilities::~Utilities()
	{
	}

	int* Utilities::ToBinary(unsigned int i, unsigned int binarr[])
	{
		const int len = sizeof(int) * 8;
		unsigned int temp;
		unsigned int q;
		unsigned int r[len];
		int index = 0;

		q = i;
		while (q > 1)
		{
			temp = q;
			q = q >> 1; // divide by 2;
			r[index] = temp % 2;
			index++;
		}

		if (q == 1)
		{
			r[index] = q;
		}

		for (int i = 0; i < len; i++)
		{
			*(binarr+i) = r[len - i - 1];
		}

		return 0;
	}

	void Utilities::ShowBinary(unsigned int arr[], int len)
	{
		int i = 0;
		while (i < len)
		{
			cout << arr[i];/*
			if (arr[i] > -1)
			{
				cout << arr[i];
			}*/
			i++;
		}
	}
}