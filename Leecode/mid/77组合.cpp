#include<iostream>
using namespace std;
#include<vector>

/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
*/


class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        backstracking(n,k,1);
        return result;
    }
    void backstracking(int n,int k,int startindex){
        if(v1.size() == k){
            result.push_back(v1);
            return;
        }
        for(int i = startindex;i<=n;i++){
            v1.push_back(i);//处理节点
            backstracking(n,k,startindex+1);//递归操作
            v1.pop_back();//回溯操作
        }
    }
};