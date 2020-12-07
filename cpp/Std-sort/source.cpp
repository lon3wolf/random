// This is a template
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
inline void ShowVector(vector<int> v)
{
    cout << endl;

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", "; 
    }

    cout << endl;
}

int main()
{

    try
    {
        vector<int> v;
        v.push_back(2);
        v.push_back(1);
        v.push_back(7);
        v.push_back(6);
        v.push_back(8);
        v.push_back(5);
        cout << "Before Sort";
        ShowVector(v);
        std::sort(v.begin(), v.end());

        cout << "After Sort";
        ShowVector(v);

    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}