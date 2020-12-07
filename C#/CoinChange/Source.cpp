#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<int> mapping;
vector<int> coins;



int FindWays(int amt)
{
	int ways = 0;
	if (mapping[amt-1] != -1)
	{
		return mapping[amt-1];
	}
	/*
	else if (amt == 0)
	{
		return 1;
	}
	else if (amt == 1)
	{
		return 1;
	}*/
	else
	{
		for (int k = 0; k < coins.size(); k++)
		{
			if (amt - coins[k] <= 0)
			{
				ways++;
				continue;
			}
			if (coins[k] < amt)
			{
				int lResult = FindWays(amt - coins[k]);
				int rResult = FindWays(coins[k]);
				if (lResult == 0 || rResult == 0)
				{
					cout << "Oh!";
				}
				ways += (lResult * rResult);
			}
		}

		mapping[amt-1] = ways;
		return ways;
	}

	return ways;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int amt, nc;
	cin >> amt >> nc;

	for (int i = 0; i < amt; i++)
	{
		mapping.push_back(-1);
	}
	
	mapping[0] = 1;

	int denomination = 0;

	for (int i = 0; i<nc; i++)
	{
		cin >> denomination;
		coins.push_back(denomination);
		cout << coins[i] << endl;
	}
	
	amt = FindWays(amt);
	cout << "Ways: " << --amt;
	cin >> amt;
	return 0;
}
