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
public:
    int bulbSwitch(int n) 
    {
        int total = 0; 

        for (int i = 1; i <= n; i++)
        {
            // default is off
            int state = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i % j == 0)
                {
                    state = !state;
                }
            }

            total += state ? 1 : 0;
        }
        
        return total;
    }
    
};

int main()
{
    try
    {
        int n = 9;
        int ret = Solution().bulbSwitch(n);
        printf("On now: %d", ret);
    }
    catch(char* ex)
    {
        cout << "Exception";
        cout << ex;
    }

    return 0;
}