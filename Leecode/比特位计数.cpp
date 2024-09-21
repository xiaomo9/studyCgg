#include<iostream>
using namespace std;
#include<vector>


/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，
计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for(int i = 0; i<n+1; i++)
        {
            int j = i;
            int count = 0;
            while(j != 0)
            {
                j = j&(j-1); // 消除最后一位的1
                count ++; 
            }
            bits.push_back(count);
        }
        return bits;
    }
};


int main()
{
    Solution S;
    
}