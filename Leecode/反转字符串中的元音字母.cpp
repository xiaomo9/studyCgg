/*
����һ���ַ��� s ������ת�ַ����е�����Ԫ����ĸ�������ؽ���ַ�����

Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���ֲ�ֹһ�Ρ�
*/
#include<iostream>
using namespace std;

class Solution {
public:
    bool isvowel(char ch) //�ж��ַ��Ƿ���Ԫ��
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