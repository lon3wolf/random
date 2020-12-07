//
// https://leetcode.com/problems/kth-largest-element-in-a-stream/
//
// cl test.cpp /EHsc

#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>

using namespace std;


void show(vector<int> v);

class KthLargest 
{
    int k  = 0;
    vector<int> v;
    
public:
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        int len = nums.size();

        for (int i=0; i < len; i++)
        {
            add(nums[i]);
        }    
    }
    
    int add(int a) 
    {
        cout << "adding " << a;

        if (v.size() >= k && v[0] >= a)
        {
            cout << "\nB1" << endl;
        }
        else if (v.size() == 0 || v[v.size() - 1] <= a)
        {
            v.push_back(a);
            cout << "\nB2" << endl;
        }
        else
        {
            cout << "\nB3" << endl;

            for (int i = v.size() -1; i >= 0; i--)
            {
                if (a >= v[i])
                {
                    v.insert(v.begin()+i+1, a);   
                    break; 
                }
                if (i == 0 && a < v[i])
                {
                    v.insert(v.begin(), a);   
                    break; 
                }
            }
        }

        if (v.size() > k)
        {
            cout << "\nB4" << " " << v[0] << " " << v[1] <<endl;
            v[0] = v[1];
            v.erase(v.begin());
        }

        show(v);
        cout << endl;
        return v[0];    
    }
};

int main()
{
    // KthLargest k(3, vector<int>({4,5,8,2}));

    // int a = k.add(3);
    // cout << "a: " << a << endl;
    
    // a = k.add(5);
    // cout << "a: " << a << endl;
    
    // a = k.add(10);
    // cout << "a: " << a << endl;
    
    // a = k.add(9);
    // cout << "a: " << a << endl;
    
    // a = k.add(4);
    // cout << "a: " << a << endl;
    

    KthLargest k(2, vector<int>({0}));

    int a = k.add(-1);
    cout << "a: " << a << endl;
    
    a = k.add(1);
    cout << "a: " << a << endl;
    
    a = k.add(-2);
    cout << "a: " << a << endl;
    
    a = k.add(-4);
    cout << "a: " << a << endl;
    
    a = k.add(3);
    cout << "a: " << a << endl;
    
    // try
    // {
    //     std::vector<int> v;

    //     std::default_random_engine generator;
    //     std::uniform_int_distribution<int> distribution(1, 99);

    //     v.insert(v.begin(), 1);
    //     v.push_back(3);
    //     v.insert(v.begin(), 0);
    //     v.push_back(100);

    //     for (int i = 0; i < 100; i++)
    //     {
    //         int dice_roll = distribution(generator);
    //         std::cout << "dice: " << dice_roll << endl;
    //         v = insert(v, dice_roll);
    //         show(v);
    //     }

    //     show(v);
    // }    
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << __LINE__ << '\n';
    // }

    return 0;
}

void show(vector<int> v)
{
    // std::cout << std::endl;
    for (int a : v)
    {
        std::cout << a << "->";
    }

    std::cout << std::endl;
}