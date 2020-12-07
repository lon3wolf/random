//https://www.hackerrank.com/challenges/max-array-sum/problem
// 
// Complexity : O(n)
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation - https://www.youtube.com/watch?v=6w60Zi1NtL8
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

inline int max(int num1, int num2)
{
    return (num1 > num2 ? num1 : num2);
}

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) 
{
    int excl = 0;   // exclude the first element
    int incl = arr[0]; // include the first element

    for(int i=1; i < arr.size(); i++)
    {
        int excl_new = max(excl, incl);
        incl = excl + arr[i]; // max sum without previous adjacent element + this element
        excl = excl_new;
    }

    return max(incl, excl);
}

int main()
{
    try
    {
        std::vector<int> list {-2, 1, 3, -4, 5};
        int result = maxSubsetSum(list);
        printf("%d \n", result);
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}