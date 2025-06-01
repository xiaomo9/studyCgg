#include<iostream>
using namespace std;
#include<cstdint>

class Solution {
public:
    int hammingWeight(int n) 
    {
        int num = 0;
        for(int i =0; i<32; i++)
        {
            if(n & (1 << i))
            {
                num ++;
            }
        }
        return num;
    }
};

int main()
{
    int a = 16;
    Solution s;
    a = s.hammingWeight(7);
    cout << a << endl;
    system("pause");

}