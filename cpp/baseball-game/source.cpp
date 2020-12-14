// This is a template
// 
// Complexity : NA
// compile command => cl /EHsc source.cpp /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
// https://leetcode.com/problems/baseball-game/

#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class Solution 
{
public:
    int calPoints(vector<string>& ops) 
    {
        vector<int> scores;
        
        for(auto op : ops)
        {
            //cout << "\nop => " << op << endl;
            if( op == "C")
            {
                //cout << "Deleting last " << scores[scores.size() - 1];
                scores.pop_back();
            }
            else if( op == "D")
            {   
                //cout << "doubling " << scores[scores.size() - 1];             
                int num = 2 * scores[scores.size() - 1];
                scores.push_back(num);
            }
            else if( op == "+")
            {
                //cout << "Adding " << scores[scores.size() - 1] << " " << scores[scores.size() - 2];
                int num = scores[scores.size() - 1] +  scores[scores.size() - 2];
                scores.push_back(num);
            }
            else
            {
                if (op[0] == '-' || op[0] == '+' || (op[0] >= '0' && op[0] <= '9'))
                {
                    //cout << "Pushing " << op;
                    int num = atoi(op.c_str());
                    scores.push_back(num);
                }
            }
        }
        
        int num = 0;
        for(auto score : scores)
        {
            //cout << score << " " ;
            num += score;
        }
        
        return num;
    }
};

int main()
{
    try
    {
        Solution s;
        vector<string> v;

        v.push_back("5");
        v.push_back("-2");
        v.push_back("4");
        v.push_back("C");
        v.push_back("D");
        v.push_back("9");
        v.push_back("+");
        v.push_back("+");

        for(auto op : v)
        {
            cout << "op-> " << op << endl;
        }

        int num = s.calPoints(v);
        cout << num  << endl;
    }
    catch(exception ex)
    {
        cout << "Exception";
        cout << ex.what();
    }

    return 0;
}
