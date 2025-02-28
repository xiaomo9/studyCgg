# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

/*
���������ַ��� s �� t ���ж������Ƿ���ͬ���ġ�

��� s �е��ַ����԰�ĳ��ӳ���ϵ�滻�õ� t ����ô�������ַ�����ͬ���ġ�

ÿ�����ֵ��ַ���Ӧ��ӳ�䵽��һ���ַ���ͬʱ���ı��ַ���˳�򡣲�ͬ�ַ�����ӳ�䵽ͬһ���ַ��ϣ�
��ͬ�ַ�ֻ��ӳ�䵽ͬһ���ַ��ϣ��ַ�����ӳ�䵽�Լ�����
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,int> mapp1;
        unordered_map<char,int> mapp2;
        if(s.size() != t.size()) // �ж�
        {
            return 0;
        }
        for(int i = 0; i<s.size(); ++i)
        {
            if(mapp1.find(s[i]) == mapp1.end()) // �ж��Ƿ����״γ��ֵ���ĸ
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