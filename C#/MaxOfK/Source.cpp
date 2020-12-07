// If we have a moving windows of length k over array of length N, find max in the window K for each movement of the window by 1
#include <iostream>
using namespace std;
int main()
{
	int k;
	cout << "Enter K:";
	cin >> k;
	if (k < 1) // check for null value or k > length of array itself or k < 1
	{
		return -1;
	}
	//int arr[9] = { 5, 4, 2, 4, 3, 7, 6, 9, 3 }; // 3: 5,4,4,7,7,9,9
	//int arr[9] = { 3, 4, 2, 1, 3, 7, 6, 9, 3 }; // 3: 4,4,3,7,7,9,9
	//int arr[9] = { 1,2,3,4,5,6,7,8,9 }; // 3: 3,4,5,5,7,8,9
	int arr[9] = { 1, 2, 3, 2, 6, 8, 4, 3, 9 }; // 3: 3,3,6,8,8,8,9 // check for null array

	int max = arr[0];
	int max2 = 0;
	int ik = 0;
	while (ik < k)
	{
		if (max < arr[ik])
		{
			max = arr[ik];
		}
		if (arr[ik] < max && arr[ik] > max2)
		{
			max2 = arr[ik];
		}
		ik++;
	}
	cout << "Max: " << max << " | max2: " << max2 << endl;
	for (int i = k; i < 9; i++)
	{
		if (max < arr[i])
		{
			max2 = max;
			max = arr[i];
		}
		if (arr[i] < max && arr[i] > max2)
		{
			max2 = arr[i];
		}
		if (max2 == arr[i - k])
		{
			max2 = max;
		}
		if (max == arr[i - k])
		{
			max = max2;
		}
		cout << "Max: " << max << " | max2: " << max2 << endl;
	}
}