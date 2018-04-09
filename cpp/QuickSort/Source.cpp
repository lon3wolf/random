// QuickSort
// http://quiz.geeksforgeeks.org/?p=2839
// 
// Complexity : 
// compile command =>  cl /o test.exe Source.cpp  /EHsc
#include <iostream>
#include "..\Common\common.h"

int Partition(int* arr, int i, int j)
{
    int x = i - 1;

    int pivot = arr[j];

    for(int k = i; k < j; k++)
    {
        if(arr[k] <= pivot)
        {
            x++;

            int t = arr[x];
            arr[x] = arr[k];
            arr[k] = t;
        }
    }

    arr[j] = arr[x+1];
    arr[x+1] = pivot;

    return x+1;
}

void  QuickSort(int* arr, int i, int j)
{
    if(i < j)
    {
        
        int p = Partition(arr, i, j);

        QuickSort(arr, i, p - 1);
        QuickSort(arr, p+1 , j);
    }
}

int main()
{
    int arr[] = {2, 4, 3, 5, 9, 7, 8, 10};
    int capacity = sizeof(arr)/sizeof(int);
    QuickSort(arr, 0, capacity - 1);

    // print the sorted array

    for(int i = 0; i < capacity; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
    
    int arr2[] = {10, 80, 30, 90, 40, 50, 70};

    capacity = sizeof(arr2)/sizeof(int);
    QuickSort(arr2, 0, capacity - 1);

    // print the sorted array

    for(int i = 0; i < capacity; i++)
    {
        std::cout << arr2[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}