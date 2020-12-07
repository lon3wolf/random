// StringSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::vector<std::vector<int>> pyramidMatrix(int n) {
	vector<vector<int>> a;

	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		v.resize(n);
		a.push_back(v);
	}

	int layer = 1;
	int end = n - (layer - 1);
	while (layer <= n)
	{
		for (int i = layer - 1; i < end; i++)
		{
			int j = layer - 1;
			a[j][i] = layer;
		}
		for (int j = layer - 1; j < end; j++)
		{
			int i = layer - 1;
			a[j][i] = layer;
		}
		for (int i = layer - 1; i < end; i++)
		{
			int j = n - layer;
			a[j][i] = layer;
		}
		for (int j = layer - 1; j < end; j++)
		{
			int i = n - layer;
			a[j][i] = layer;
		}
		end--;
		layer++;
	}

	return a;
}

void CheckArray(vector<string> sarr, int len)
{

	for (int i = 0; i < len; i++) {
		if (sarr[i] == "") {
		}
		std::sort(sarr[i].begin(), sarr[i].end());
		//cout << sarr[i] << endl;
	}

	for (int i = 0; i < len; i++) {
		for (int j = 1; j < len; j++) {
			char a = sarr[j - 1][i];
			char b = sarr[j][i];

			if (a > b) {
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
}

//int main() {
//	int tc = 0;
//	cin >> tc;
//	//string n;
//	/*while (tc>0){
//		tc--;
//		int len = 0;
//		cin >> len;
//		vector<string> strings(0);
//		string str = "";
//		cin.clear();
//		for (int i = 0; i < len; i++){
//			getline(cin, str);
//			if (str.length() == 0)
//			{
//				i--;
//				continue;
//			}
//			if (str.length() != 0){
//				strings.push_back(str);
//			}
//		}
//		CheckArray(strings, len);
//	}*/
//	vector<vector<int>> a = pyramidMatrix(tc);
//
//	for (int i = 0; i < tc; i++)
//	{
//		for (int j = 0; j < tc; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


vector<vector<char>> scanGrid(int m, int n) {
	vector<vector<char>> a;
	a.reserve(m);
	for (int i = 0; i < m; i++) {
		vector<char> c;
		c.reserve(n);
		string str = "";
		while (str == "") {
			getline(cin, str);
		}
		for (int j = 0; j < n; j++) {
			c.push_back(str[j]);
		}
		a.push_back(c);
	}

	return a;
}

void showGrid(int m, int n, vector<vector<char>> arr) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

bool arrmatch(int m, int n, vector<vector<char>> main, int i, int j, vector<vector<char>> s, int x, int y) {
	for (int a = x; a < x + i; a++)
	{
		for (int b = y; b < y + j; b++)
		{
			if (s[a - x][b - y] != main[a][b])
			{
				return false;
			}
		}
	}

	return true;
}

void arrfind(int m, int n, vector<vector<char>> main, int i, int j, vector<vector<char>> s) {
	if (m < i || n < j) {
		cout << "NO";
	}

	char searchChar = s[0][0];

	for (int a = 0; a < m - i; a++)
	{
		for (int b = 0; b < n - j; b++)
		{
			if (main[a][b] == searchChar) {
				if (arrmatch(m, n, main, i, j, s, a, b))
				{
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	int tc = 0;
	cin >> tc;
	while (tc > 0) {
		tc--;
		int m = 0, n = 0;
		cin >> m >> n;
		vector<vector<char>> a = scanGrid(m, n);
		//showGrid(m, n, a);
		int i = 0, j = 0;
		cin >> i >> j;
		vector<vector<char>> s = scanGrid(i, j);
		//showGrid(i, j, s);

		arrfind(m, n, a, i, j, s);
	}
	return 0;
}