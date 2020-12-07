// PascalTriangle.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int* lA, const int len, int layer)
{
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < (layer - len + i / 2); j++)
		{
			cout << " ";
		}
		cout << lA[i] << "";
	}
}

int* GetNext(int* lA, const int len)
{
	const int length = len + 1;
	int* lastArray = (int*)malloc((len + 1) * sizeof(int));
	for (int i = 0; i < len + 1; i++)
	{
		if (i == 0 || i == len)
		{
			*(lastArray + i) = 1;
		}
		else
		{
			*(lastArray + i) = lA[i - 1] + lA[i];
		}
	}

	return lastArray;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int level;
	cout << "Enter level:";
	cin >> level;
	int* lastArray = new int[]{ 1 };
	int nElements = 1;
	for (int i = 1; i < level; i++)
	{
		print(lastArray, nElements, level);
		lastArray = GetNext(lastArray, nElements);
		nElements++;
	}
	fflush(stdin);
	getchar();
	return 0;
}
