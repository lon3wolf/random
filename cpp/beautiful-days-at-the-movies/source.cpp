//https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
// 
// Complexity : O(n)
// compile command => cl contigousSum.cpp /o test.exe

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int maxNumber = 1000000;

int reverseNumber(int i)
{
    int p = i;
    int reverse = 0;
    int unit = 1;
    for(int n = maxNumber; n != 0 && i != 0; n=n/10)
    {
        int k = i/n;

        if(k == 0 && unit == 1)
            continue;
        else
        {
            i = i - (k*n);
            reverse += k*unit;
            unit = unit * 10;
        }
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
        //cout << "Number" << a << " reverse  " << rev << endl;
        double calc =  (double)(a - rev)/(double)k;
        cout << floor(calc) <<  " " << ceil(calc) << endl;
        calc = floor(calc) - ceil(calc);
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
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
