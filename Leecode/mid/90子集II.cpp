#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 
子集
（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> v1;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return result; 
    }
    void backtracking(vector<int>& nums,int startindex){
        result.push_back(v1);
        if(startindex == nums.size()) return;
        for(int i = startindex; i < nums.size(); i++){
            v1.push_back(nums[i]);
            backtracking(nums,i+1);
            v1.pop_back();
            while(i<nums.size()-1 && nums[i]==nums[i+1]){ // 跳过重复元素，且不影响下一个迭代循环
                i++;
            }
        }
    }

};


int main(){
    Solution s;
    vector<int> v = {1,2,2};
    s.subsetsWithDup(v);
}