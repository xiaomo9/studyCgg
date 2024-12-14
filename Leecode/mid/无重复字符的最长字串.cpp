#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int max_len = 0;
        for(int l = 0, r=0; r<s.size();++r){
            while(char_set.count(s[r])){//当此元素存在  
                char_set.erase(s[l]); //删除左指针所指元素
                l++;// 移动左指针
            }
            char_set.insert(s[r]); //插入右指针所指的变量
            max_len = max(max_len,r-l+1);
            }
            return max_len;
        }
};