#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 (数组中会存在重复的数字)
*/


class Solution {
public:
    vector<vector<int>> result;
    vector<int> v1;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return result;
    }

    void backtracking(vector<int>& candidates, int target,int startindex){
        if(sum==target){
            result.push_back(v1);
            return;
        }
        if(sum > target) return;
        for(int i = startindex;i<candidates.size();i++){
            v1.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates,target,i+1);
            v1.pop_back();
            sum-=candidates[i];
            while(candidates[i]==candidates[i+1]&&i<candidates.size()){
                i++;
            }
        }
    }
};