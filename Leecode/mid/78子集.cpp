#include<iostream>
using namespace std;
#include<vector>

/*

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集
（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
    void backtracking(vector<int>& nums,int startindex){
        result.push_back(v1);
        if(startindex == nums.size()){
            return;
        }
        for(int i = startindex; i< nums.size(); i++){
            v1.push_back(nums[i]);
            backtracking(nums,i+1);
            v1.pop_back();
        }
    }
};