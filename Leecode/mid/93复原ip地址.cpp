#include<iostream>
using namespace std;
#include<vector>


/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
这些地址可以通过在 s 中插入 '.' 来形成。你不能 重新排序或删除 s 中的任何数字。
你可以按 任何 顺序返回答案。
*/
class Solution {
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,0);
        return result;
        }
    void backtracking(string s, int startindex, int pointnum){ //回溯算法
        if(pointnum == 3){
            if(is_vail(s,startindex,s.size()-1)){
                result.push_back(s);
            }   
            return;
        }
        for(int i = startindex;i<s.size()-1;i++){
            if(is_vail(s,startindex,i)){
                s.insert(s.begin()+i+1,'.'); //添加分割符.
                pointnum += 1;//计数范围
                backtracking(s,i+2,pointnum);// 递归
                pointnum -= 1;
                s.erase(s.begin()+i+1);
            }
        }
    }

    bool is_vail(string s,int start,int end){//判断是否符合ip地址规则
        int sum = 0;
        if(start > end) return false;
        for(int i = start;i <= end;i++){ //左闭右闭区间
            int num = s[i] - '0';
            if(s[i]<'0' || s[i]>'9') return false;//非数字字符
            if(s[start] == '0' && start != end) return false; //0后面还右数字
            sum  = sum*10 + num;
            if(sum > 255) return false; //如果大于255不合法
        }
        return true;
    }
};