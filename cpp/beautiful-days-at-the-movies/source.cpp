//https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe

// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

vector<string> split_string(string);
const int maxNumber = 1000000;

int reverseNumber(const int i)
{
    int p = i;
    int reverse = 0;
    int unit = 1;
    /*
        250

        1000000

        0, 1000000 => 250
        0, 100000 => 250
        0, 10000 => 250
        0, 1000 => 
        2, 100 => 50
        5, 10 => 0
        0, 1 => 0
        => 52
    */

    for(int n = maxNumber; p != 0; ) ///   n=10 p=50  reverse=2   unit=1 =>  52
    {
        int k = (p/n)*(n);      // k = 50
        p = p - k;              // p = 0
        k = k/n;                // k = 2
        n = n/10;               // n = 10
        k = (unit)*k;

        if(k != 0 || unit != 1)
        {   
            unit *= 10;
        }

        reverse += k;
    }

    // cout << "Number: " << p << " reverse: " << reverse << endl;
    return reverse;
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) 
{
    int beautifulDays = 0;
    for(int a=i; a<=j; a++)
    {
        int rev = reverseNumber(a);
        cout << "Number" << a << " reverse  " << rev << endl;
        int calc =  std::abs(a - rev) %k;
        if(calc == 0)
        {
            //cout << "Beautiful Day!" << endl;
            beautifulDays++;
        }
    }
    
    return beautifulDays;
}

 
int main()
{

    try
    {
        /*
        int i = 949488;

        int j = 1753821;

        int k = 5005440;
        */
        int i = 10;

        int j = 201;

        int k = 10;

        int result = beautifulDays(i, j, k);

        cout << result << "\n";
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}