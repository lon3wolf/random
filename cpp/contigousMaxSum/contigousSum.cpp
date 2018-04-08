// Write an efficient C program to find the sum of contiguous subarray within 
// a one-dimensional array of numbers which has the largest sum. 
// https://www.geeksforgeeks.org/?p=576
// 
// This uses Kadane’s Algorithm along with range tracking to display star and end of contigous range
// Complexity : O(n)
// compile command => cl contigousSum.cpp /o test.exe
#include <iostream>

using namespace std;
int main()
{
	const int arr[] = {-2, -3, 4, -1, -2, -1, 5, -3};
	const int len = 8;
	int startIndex = 0;
	int endIndex = 0;
	int sumSoFar = 0;

	int maxSum = 0;
	int maxI = 0;
	int maxJ = 0;

	// traverse the array
	for(int i = 0; i < len; i++)
	{
		sumSoFar += arr[i];
		endIndex = i;
		if(sumSoFar < 0)
		{
			sumSoFar = 0;
			startIndex = i+1;
			endIndex = i+1;
		}

		if(maxSum < sumSoFar)
		{	
			maxSum = sumSoFar;
			maxI = startIndex;
			maxJ = endIndex;

		}	
	}

	cout << "Max Sum: " << maxSum << " Range: " << maxI << " - " << maxJ << endl;

	return 0;
}
