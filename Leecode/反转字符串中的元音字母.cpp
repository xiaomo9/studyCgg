/*
给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
*/
#include<iostream>
using namespace std;

class Solution {
public:
    bool isvowel(char ch) //判断字符是否是元音
    {
        string vowels = "aeiouAEIOU";
        return vowels.find(ch) != string::npos;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i<j)
        {
            while(!isvowel(s[i])&&i<j) i++;
            while(!isvowel(s[j])&&i<j) j--;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;j--;
        }
        return s;
    }
};

int main()
{
    string s = "leetcode";
    Solution s1;
    s = s1.reverseVowels(s);
    cout << s << endl;
    system("pause");
}