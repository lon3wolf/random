// This is a template
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class Solution 
{   

    string RemoveWhiteSpace(string str)
    {
        char* s = new char[str.length()+1];
        char space = ' ';
        int t = 0;
        
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != space)
            {
                s[t] = str[i];
                //printf("- %c\n", str[i]);
                t++;
            }
        }

        s[t] = '\0';
        
        return string(s);
    }

    string Remove0(string str)
    {
        char* s = new char[str.length()+1];
        char hyphen = '-';
        int index = 0;
        int t = 0;
        int n  = 0;
        if (str[index] == '-' && (str[index+1] >= '1' && str[index+1] <= '9'))
        {
            return str;
        }
        if (str[index] == '-')
        {
            index++;
            s[t] = '-';
            t++;
        }
        for (int i = t; i < str.length(); i++)
        {
            if (str[i] >= '1' && str[i] <= '9')
            {
                n = 1;
                s[t] = str[i];
                t++;
            }
            if (str[i] == '0' && n != 0)
            {
                s[t] = str[i];
                t++;
            }
        }

        s[t] = '\0';
        
        return string(s);
    }
    
    string RemoveAlpha(string str)
    {
        char* s = new char[str.length()+1];
        char hyphen = '-';
        int t = 0;
        //printf("\n-->%c\n", str[0]);
        if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
        {
            return "";
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == hyphen || (str[i] >= '0' && str[i] <= '9'))
            {
                //printf("->%c\n", str[i]);
                s[t] = str[i];
                t++;
            }
        }

        s[t] = '\0';
        
        //printf("\n%s\n", s);
        return string(s);
    }

    bool isValid(string s)
    {
        if (s.length() == 0)
        {
            return false;
        }

        int index = 0;
        
        if (s[index] == '-')
        {
            index++;
        }
        
        for (int i = index; i < s.length(); i++)
        {
            if (s[i] == '-')
            {
                return false;
            }
            if (s[i] != '-' && (s[i] >= '0' && s[i] <= '9'))
            {
                return true;
            }
        }

        return false;
    }

    int getNum(string s)
    {
        int multiplier = 1;
        multiplier = s[0] == '-' ? -1 : 1;
        
        printf("\n str: %s", s.c_str());
        printf("\n multiplier: %d", multiplier);
        printf("\nLenght: %d", s.length());
        int number = 0;
        int num = 0;
        unsigned int unit = (int) (multiplier == -1 ? pow(10, (s.length() - 2)) : pow(10, (s.length() - 1)));
        if(unit > 10000000000)
        {
            if (multiplier > 0)
            {
                return pow(2, 31) - 1;
            }
            else
            {
                return multiplier* pow(2, 31);
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '-')
            {
                printf("\nUnit: %d\n", unit);
                
                num = (int)(s[i] - '0');
                num = unit * num;
                unit /= 10;
                number += num;
            }
        }

        return multiplier * number;
    }

public:
    int myAtoi(string s) 
    {
        string str = RemoveWhiteSpace(s);
        //printf("%s\n", str.c_str());
        
        str = RemoveAlpha(str);
        //printf("%s\n", str.c_str());
        
        if (!isValid(str))
        {
            printf("\nIs not Valid\n\n");
            
            return 0;
        }

        printf("\nNum: %d", getNum(str));
        return getNum(str);
    }
};

int main()
{

    try
    {
        Solution s;
        s.myAtoi("-91283472332");
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}