#include <iostream>

using namespace std;
int arr [] = { 6, 10, 13, 5, 8, 3, 2, 11 };
int len = 8;


int Partition(int start, int end)
{
	if (start >= end)
	{
		return start;
	}
	int p = start;
	int x = start;

	for (int j = p+1; j < end; j++)
	{
		if (arr[j] <= arr[start])
		{
			p++;
			int t = arr[p];
			arr[p] = arr[j];
			arr[j] = t;
 		}
	}
	
	int t = arr	[start];
	arr[start] = arr[p];
	arr[p] = t;
	return p;
}

void QuickSort( int start, int end)
{
	if (start >= end)
	{
		return;
	}
	else
	{
		int partition = Partition(start, end);
		QuickSort(start, partition);
		QuickSort(partition + 1, end);
	}
}


int main()
{
	cout << "Old Array:: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "Quick Sorting::" << endl;
	try
	{
		QuickSort(0, len);
	}
	catch(exception ex)
	{
		cout << ex.what() << endl;
	}
	cout << endl << "Sorted:: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	int dummy;
	cin >> dummy;
}