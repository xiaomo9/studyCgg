#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<string> result;

    void add_kuohao(string s1,int left,int right){
        if(left == 0 &&right==0){
            result.push_back(s1);
            return;
        }
        if(left<right){
            if(left>0) add_kuohao(s1+"(",left-1,right);
            add_kuohao(s1+")",left,right-1);
        }
        if(left == right){
            add_kuohao(s1+"(",left-1,right);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n==0) return result;
        add_kuohao("",n,n);
        return result;
    }
};

int main(){
    Solution s1;
    s1.generateParenthesis(3);
}