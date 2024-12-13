#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。
你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
    void backtracking(vector<int>& nums, int startindex){
        if(v1.size() > 1) {
            result.push_back(v1);
        }
        if(startindex >= nums.size()) return; // 到达根节点结束递归
        unordered_set<int> set1;
        for(int i = startindex; i< nums.size(); i++){
            if(set1.find(nums[i])!=set1.end() || !v1.empty()&&nums[i] < v1.back()) continue; // 当此数在该层已经用过，或者此数比前一个数小，则跳过
            v1.push_back(nums[i]);
            set1.insert(nums[i]); //记录被用过的数
            backtracking(nums,i+1); //递归
            v1.pop_back();//回溯
        }
    }
};