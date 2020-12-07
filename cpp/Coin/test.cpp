#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>

using namespace std;


void show(vector<int> v);
vector<int> insert(vector<int> v, int a);


class KthLargest {
    int k  = 0;
    vector<int> v;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        int len =  nums.size();
        cout << "Len: " << len;

        for (int i=0; i < len; i++)
        {
            cout << "inserting " << nums[i] << endl;
            v = insert(v, nums[i]);
            show(v);
        }    
    }
    
    int add(int val) 
    {
        v = insert(v, val);

        if (v.size() - k < 0)
        {
            return -1;
        }

        show (v);

        return v[v.size() - k];    
    }
    
    vector<int> insert(vector<int> v, int a) 
    {   
        int i = 0;
        int inc = 10;

        if (v.size() == 0)
        {
            v.push_back(a);
            return v;
        }
        if (v.size() > 0 && v[v.size()-1] < a)
        {
            v.push_back(a);
            return v;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (i+inc > v.size())
            {
                // disable
                inc = 0;
            }

            if (inc != 0 && v[i] < a && v[i+inc] < a)
            {
                i+= inc;
                continue;
            }

            if (v[i-1] < a && v[i] > a)
            {
                v.insert(v.begin() + i, a);   
                break; 
            }
            else if (v[i] == a)
            {
                v.insert(v.begin() + i, a);   
                break;
            }
        }

        return v;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    KthLargest k(3, vector<int>({4,5,8,2}));

    int a = k.add(3);
    cout << "a: " << a << endl;
    
    a = k.add(5);
    cout << "a: " << a << endl;
    
    a = k.add(10);
    cout << "a: " << a << endl;
    
    a = k.add(9);
    cout << "a: " << a << endl;
    
    a = k.add(4);
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

vector<int> insert(vector<int> v, int a) 
{   
    int i = 0;
    int inc = 10;
    
    if (v[v.size()-1] < a)
    {
        v.push_back(a);
        return v;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (i+inc > v.size())
        {
            // disable
            inc = 0;
        }

        if (inc != 0 && v[i] < a && v[i+inc] < a)
        {
            i+= inc;
            continue;
        }

        if (v[i-1] < a && v[i] > a)
        {
            cout << "inserting" << endl;
            v.insert(v.begin() + i, a);   
            break; 
        }
    }

    return v;
}

void show(vector<int> v)
{
    std::cout << std::endl;
    for (int a : v)
    {
        std::cout << a << "->";
    }

    std::cout << std::endl;
}