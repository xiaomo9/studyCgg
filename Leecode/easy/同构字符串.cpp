# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，
相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,int> mapp1;
        unordered_map<char,int> mapp2;
        if(s.size() != t.size()) // 判断
        {
            return 0;
        }
        for(int i = 0; i<s.size(); ++i)
        {
            if(mapp1.find(s[i]) == mapp1.end()) // 判断是否是首次出现的字母
            {
                mapp1[s[i]] = i;
            }
            if(mapp2.find(t[i]) == mapp2.end())
            {
                mapp2[t[i]] = i;
            }

            if(mapp1[s[i]] != mapp2[t[i]])
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    Solution s;
    string s1 = "abcde";
    string s2 = "jmhjk";
    cout << s.isIsomorphic(s1,s2) << endl;
    system("pause");
}