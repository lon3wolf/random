// Longest increasing subsequence
// https://www.youtube.com/watch?v=fV-TF4OvZpk
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int init = 0;
int *lenArr;

void LIS_Setup(int n)
{
    if (init != 0)
    {
        return;
    }

    lenArr = new int[n];

    cout << "Init array" << endl;
    for (int i=0; i < n; i++)
    {
        lenArr[i] = 1;
        cout << lenArr[i] << " ";
    }
    cout << endl;
    init = 1;
}

inline int max(int a, int b)
{
    return (a > b)? a : b; 
}

inline void PrintArray(int arr[], int n)
{
    cout << endl << endl << "[ ";
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << " ]" << endl;
}

// Longest increasing subsequence
int LIS(int arr[], int n)
{
    LIS_Setup(n);
    int len = 1;
    if (n == 0 || n == 1)
    {
        return n;
    }

    // [3, 10, 2, 1, 20]
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[j] > arr[i])           // 20
            {
                lenArr[j] = max(lenArr[j], lenArr[i] + 1);  // 1 2 1 1 3
                len = max(len, lenArr[j]);  //3
            }
        }
    }

    return len;
}

// Longest non-decreasing subsequence
int LNDS(int arr[], int n)
{
    LIS_Setup(n);
    int len = 1;
    if (n == 0 || n == 1)
    {
        return n;
    }
    
    // [3, 10, 2, 1, 20]
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[j] >= arr[i])           // 20
            {
                lenArr[j] = max(lenArr[j], lenArr[i] + 1);  // 1 2 1 1 3
                len = max(len, lenArr[j]);  //3
            }
        }
    }

    return len;
}

int main()
{
    int arr[] = {3, 10, 2, 1, 20};
    int arr2[] = {-1,3,4,5,2,2,2,2};
    try
    {
        PrintArray(arr,5);
        
        cout << LIS(arr, 5) << endl;
        init = 0;

        cout << LNDS(arr, 5) << endl; 
        init = 0;
        
        PrintArray(arr2,8);
        
        cout << LIS(arr2, 8) << endl;
        init = 0;
        
        cout << LNDS(arr2, 8) << endl;
        init = 0;
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}