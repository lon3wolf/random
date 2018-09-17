//https://www.hackerrank.com/challenges/kangaroo/problem
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe

// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) 
{
    int d = std::abs(x2 - x1);
    int v = std::abs(v2 - v1);
    if(x2 > x1 && v2 >= v1)
    {
        return "NO";
    }
    if(x1 > x2 && v1 >= v2)
    {
        return "NO";
    }
    if(d == 0)
    {
        return "YES";
    }
    else if( v == 0)
    {
        return "NO";
    }

    // cout << d <<  " ::  "<< v << endl; 
    if(d % v == 0)
    {
        return "YES";
    }

    return "NO";
}

int main()
{
    try
    {
        int k1x = 21; //21 6 47 3
        int k1v = 6;

        int k2x = 47;
        int k2v = 3;
        string result = kangaroo(k1x, k1v, k2x, k2v);
        printf("%s \n", result.c_str());
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}