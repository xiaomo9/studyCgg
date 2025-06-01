#include<iostream>
using namespace std;
#include<vector>

/*
给你一个字符串 s，找到 s 中最长的回文子串。
*/

class Solution {
public:
    bool is_huiwen(string &s,int beg, int end){
        while(beg<=end){
            if(s[beg]==s[end]){
                beg++;end--;
            }
            else return 0;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        int max_len = 0;
        int begin=0;
        for(int i=0; i<s.size();++i){ //左指针
            for(int j = i; j<s.size();++j){
                if((j-i+1)>max_len&&is_huiwen(s,i,j)){// 是回文串
                    max_len = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,max_len);
    }
};