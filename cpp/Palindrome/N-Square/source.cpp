//Largest Palindrome in a string
//- Discussing N^2 Dynamic solution
//- Odd-Even N^2 solution
// O(n) solution using Manacher's solution
// Ref Links - 
// - https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// - https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
// - (It has 4 parts) https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe

// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int longestPalSubstr(string str)
{
    int n = str.length();
    
    bool test[n][n];
    memset(test, 0, sizeof(test));

    printf("%d", sizeof(test));
       
    return n;
}

int main()
{
    try
    {
        string str = "abcba";
        printf("Length: %d", longestPalSubstr(str));
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}