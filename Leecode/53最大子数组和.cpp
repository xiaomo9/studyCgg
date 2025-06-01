#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_pre = 0;
        int result = 0;
        int pre = 0;
        for(auto num : nums){
            pre += num;
            result = max(result, pre - min_pre);
            min_pre = min(min_pre,pre);
        }
        return result;
    }
};