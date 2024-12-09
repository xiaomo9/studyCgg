#include<iostream>
using namespace std;
#include<vector>


/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        //递归解决这个问题
        if(n<=0) return result;
        generate("",n,n);
        return result;
    }
    void generate(string s,int left, int right){
        if(left==0 &&right==0)
        {
            result.push_back(s);
            return;
        }
        if(left == right){
            // 若左右括号数一致，此时只能插入（
            generate(s+'(',left-1,right);
        }
        else if(left < right){
            //若左括号多余右括号，插入左右都可以
            if(left>0) generate(s+'(',left-1,right);
            generate(s+')',left,right-1);
        }
    }
};