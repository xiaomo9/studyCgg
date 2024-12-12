#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return result;
    }
    void backtracking(int k,int n,int startindex){
        int sum = accumulate(v1.begin(),v1.end(),0);
        if(v1.size() == k&&sum == n){ //终止条件
            result.push_back(v1);
            return;
        }
        if(sum > n) return;
        for(int i = startindex;i<=9;i++){
            v1.push_back(i);
            backtracking(k,n,i+1);
            v1.pop_back();
        }
    }
};