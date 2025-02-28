#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

/*
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i =1; i<nums.size+1; i++)
        {
            auto itr = find(nums.begin(), nums.end(), i);
            if(itr == nums.end()) return i;
        }
        return 0;
    }
};