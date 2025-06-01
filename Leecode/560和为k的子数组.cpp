#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sums_map;
        int result = 0;
        int sum=0;
        for(int i = 0; i< nums.size(); ++i){
            sum = sum + nums[i];
            sums_map[sum]++;
            int cha = sum - k;
            result += sums_map[cha];
        }

        return result;
    }
};