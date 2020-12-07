// IntReverse.cpp : Defines the entry point for the console application.
//#include <iostream>
#include "stdafx.h"
#include <string>
#include "targetver.h"
#include <stdlib.h>   // For _MAX_PATH definition
#include <stdio.h>
#include <malloc.h>
#include <tchar.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int reverse_number(int n) {
	char* s = (char*) malloc(10);
	_itoa_s(n, s, 10, 10);
	int len = strlen(s);
	char c = s[len-1];
	
	while (c == '0'){
		len--;
		c = s[len-1];
	}

	s[len] = '\0';

	if (len > 1){
		int i = 0, j = len - 1;
		while (i <= j){
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			i++; j--;
		}
	}
	
	cout << s << endl;
	return atoi(s);
}
int reverse_number2(int n) {
	int r = 0;
	while (n != 0) {
		int d = n % 10;
		r = r * 10 + d;
		n /= 10;
	}
	return r;
}

int nextPrime(int n) {

	for (int i = n + 1;; i++) {
		int isPrime = true;
		for (int divisor = 2; divisor <= n; divisor++) {
			if (i % divisor == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			return i;
		}
	}
}

const char* Sort(char* str, int len)
{
	std::sort(str, str + len);
	return str;
}

void Minimize(char* str, int i, int j)
{
	if (i == j)
	{
		return;
	}
	else{
		std::sort(str + i, str + j);
	}
}

int Maximize(char* str, int len)
{
	int j = len;
	int k = -1;
	while (j > 1){
		j--;
		for (int i = len - 1; i >= 1;)
		{
			if (str[j] > str[i - 1])
			{
				k = i - 1;
				break;
			}
			else
			{
				i--;
			}
		}
		if (k != -1){
			break;
		}
	}
	if (k != -1)
	{
		char c = str[k];
		str[k] = str[j];
		str[j] = c;
	}
	else{
		return -1;
	}
	return (k + 1);
}

void CheckArray(vector<string> sarr)
{
	int len = sarr.size();

	for (int i = 0; i < len; i++){
		std::sort(sarr[i].begin(), sarr[i].end());
		cout << sarr[i] << endl;
	}

	for (int i = 0; i < len; i++){
		for (int j = 1; j < len; j++){
			char a = sarr[j - 1][i];
			char b = sarr[j][i];

			if (a > b){
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
}

int main()
{
	char str[] = "22:22:30";
	char* ctx = NULL; 
	char* part = strtok_s(str, ":", &ctx);
	
	while (part != NULL)
	{
		cout << part << endl;
		part = strtok_s(NULL, ":", &ctx);		
	}
	
	//int tc = 0, len = 0;
	//cin >> tc;
	//string str2;
	//getline(cin, str2);
	////cout << tc << endl;
	//while (tc > 0){
	//	tc--;
	//	string str;
	//	getline(cin, str);
	//	len = 0;
	//	//cout  << str << endl;
	//	len = str.length();
	//	char* s = (char*)str.c_str();
	//	int  k = Maximize(s, len);
	//	if (k == -1){
	//		cout << "no answer" << endl;
	//		continue;
	//	}

	//	Minimize(s, k, len);
	//	cout << s << endl;
	//}
	return 0;
}

