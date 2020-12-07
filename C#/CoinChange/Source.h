#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int amt, nc;
	cin >> amt >> nc;
	int denomination = 0;
	vector<int> coins;

	for (int i = 0; i<nc; i++)
	{
		cin >> denomination;
		coins.push_back(denomination);
		cout << coins[i] << endl;
	}

	return 0;
}
