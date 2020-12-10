// This is a template
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

vector<string> multiply(vector<string> ar1, vector<string> ar2)
{
    int l1 = ar1.size();
    int l2 = ar2.size();

    vector<string> ar;
    for (int i = 0 ; i < l1; i++)
    {
        for (int j = 0 ; j < l2; j++)
        {
            ar.push_back(ar1[i] + ar2[j]);
        }
    }
    
    return ar;
}

int toInt(char c)
{
    int x = (int)c;
    x = x - 48;
    return x;
}

vector<string> letterCombinations(string digits) 
{
    vector<string> arr;
    vector<vector<string>> v;
    
    vector<string> a; 
    a.push_back("a");  a.push_back("b");  a.push_back("c");
    v.push_back(a); a.clear();
    
    a.push_back("d");  a.push_back("e");  a.push_back("f");
    v.push_back(a); a.clear();

    a.push_back("g");  a.push_back("h");  a.push_back("i");
    v.push_back(a); a.clear();

    a.push_back("j");  a.push_back("k");  a.push_back("l");
    v.push_back(a); a.clear();
    
    a.push_back("m");  a.push_back("n");  a.push_back("o");
    v.push_back(a); a.clear();

    a.push_back("p");  a.push_back("q");  a.push_back("r"); a.push_back("s");
    v.push_back(a); a.clear();

    a.push_back("t");  a.push_back("u");  a.push_back("v");
    v.push_back(a); a.clear();

    a.push_back("w");  a.push_back("x");  a.push_back("y"); a.push_back("z");
    v.push_back(a); a.clear();
    
    arr.push_back("");
    for (int x = 0; x < digits.length(); x++)
    {
        int num = toInt(digits[x]);
        vector<string> m = v[num - 2];
        arr = multiply(arr, m);
    }

    return arr;
}

int main()
{
    try
    {
        string test = "239";
        vector<string> arr;
        vector<vector<string>> v;
        
        vector<string> a; 
        a.push_back("a");  a.push_back("b");  a.push_back("c");
        v.push_back(a); a.clear();
        
        a.push_back("d");  a.push_back("e");  a.push_back("f");
        v.push_back(a); a.clear();

        a.push_back("g");  a.push_back("h");  a.push_back("i");
        v.push_back(a); a.clear();

        a.push_back("j");  a.push_back("k");  a.push_back("l");
        v.push_back(a); a.clear();

        
        a.push_back("m");  a.push_back("n");  a.push_back("o");
        v.push_back(a); a.clear();

        a.push_back("p");  a.push_back("q");  a.push_back("r"); a.push_back("s");
        v.push_back(a); a.clear();

        a.push_back("t");  a.push_back("u");  a.push_back("v");
        v.push_back(a); a.clear();

        a.push_back("w");  a.push_back("x");  a.push_back("y"); a.push_back("z");
        v.push_back(a); a.clear();
        
        arr.push_back("");
        for (int x = 0; x < test.length(); x++)
        {
            int num = toInt(test[x]);
            vector<string> m = v[num - 2];
            arr = multiply(arr, m);
        }
        
        for (auto s : arr)
        {
            printf("%s ", s.c_str());
        }
    }
    catch(string* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}