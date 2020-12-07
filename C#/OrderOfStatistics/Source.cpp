#include <iostream>

using namespace std;

int Partition(int* arr,int start, int end)
{
	if (start > end)
	{
		return start;
	}
	int p = start;

	for (int j = p + 1; j < end; j++)
	{
		if (arr[j] <= arr[start])
		{
			p++;
			int t = arr[p];
			arr[p] = arr[j];
			arr[j] = t;
		}
	}

	int t = arr[start];
	arr[start] = arr[p];
	arr[p] = t;
	return (p);
}
void PrintArr(int *arr, int len)
{
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void PrintArr(int *arr, int p, int q)
{
	cout << endl;
	for (int i = p; i < q; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int FindKthMax(int *arry, int p, int q, int k)
{
	//PrintArr(arry, p, q);
	int pivot = 0;
	//cout << p << "," << q << endl;
	if (k == p)
	{
		//PrintArr(arry, p, q);
		pivot = Partition(arry, p, q);
		if (k == pivot)
		{
			return arry[pivot];
		}
	}
	int index = 0;
	pivot = Partition(arry, p, q);
	if (pivot < k)
	{
		index = FindKthMax(arry, pivot + 1, q, k);
	}
	else if (pivot >= k)
	{
		index = FindKthMax(arry, p, pivot, k);
	}
	return index;
}

int main()
{
	int len = 9;
	int arr[] = {6,9,7,2,1,3,5,8,4};
	int knum = 0;
	knum = FindKthMax(arr, 0, 9, 0);
	cout << "Kth Num: " << knum << endl;
	knum = FindKthMax(arr, 0, 9, 2);
	cout << "Kth Num: " << knum << endl;
	knum = FindKthMax(arr, 0, 9, 3);
	cout << "Kth Num: " << knum << endl;
	knum = FindKthMax(arr, 0, 9, 5);
	cout << "Kth Num: " << knum << endl;
	knum = FindKthMax(arr, 0, 9, 6);
	cout << "Kth Num: " << knum << endl;
	knum = FindKthMax(arr, 0, 9, 8);
	cout << "Kth Num: " << knum << endl;
	cin >> len;
	return 0;
}