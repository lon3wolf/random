// Coin Change
// https://www.hackerrank.com/challenges/ctci-coin-change/problem
// Complexity : NA
// compile command => cl /EHsc source.cpp /Zi /Debug /o test.exe
// Explanation: NA
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

std::unordered_map<int, int> m_ways(100);

vector<string> split_string(string);


void print(int n, vector<int> coins)
{
    cout << endl <<  n << endl;
    for(int i=0; i < coins.size(); i++)
    {
        cout << coins[i] << " " ;
    }
}

// Complete the ways function below.
int ways(int n, vector<int> coins) 
{
    print(n, coins);

    if (n < 0)
    {
        return 0;
    }
    else if (n >= 0 && m_ways.find(n) != m_ways.end())
    {
        return m_ways[n];
    }

    int m_ways_n = 0;

    for (int itr = 0; itr < coins.size(); itr++)
    {
        int coin = coins[itr];
        m_ways_n += ways(n - coin, coins);
        
        coins[itr] = coin;
        m_ways_n += ways(n - coin, coins);
    }

    m_ways[n] += m_ways_n;

    return m_ways[n];
}

// Driver code 
int main()  
{  
    std::vector<int>Coins = { 1, 5, 10 };  
    m_ways[0] = 1;
    int n = ways(12, Coins);  
    cout << endl <<  n << std::endl;
}  

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));
    
//     m_ways[0] = 1;

//     string nm_temp;
//     getline(cin, nm_temp);
//     nm_temp = "8 3";

//     vector<string> nm = split_string(nm_temp);

//     int n = stoi(nm[0]);

//     int m = stoi(nm[1]);

//     string coins_temp_temp;
//     getline(cin, coins_temp_temp);
//     coins_temp_temp = "1 3 5";
//     vector<string> coins_temp = split_string(coins_temp_temp);

//     vector<int> coins(m);

//     for (int i = 0; i < m; i++) {
//         int coins_item = stoi(coins_temp[i]);

//         coins[i] = coins_item;
//     }

//     int res = ways(n, coins);

//     fout << res << "\n";
//     cout << res  << std::endl;

//     fout.close();

//     return 0;
// }

vector<string> split_string(string input_string) {
    cout << input_string << std::endl;
    
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y && x == ' ';
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