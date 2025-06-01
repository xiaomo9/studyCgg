#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
/*
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ��ĳ��ȡ�
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int max_len = 0;
        for(int l = 0, r=0; r<s.size();++r){
            while(char_set.count(s[r])){//����Ԫ�ش���  
                char_set.erase(s[l]); //ɾ����ָ����ָԪ��
                l++;// �ƶ���ָ��
            }
            char_set.insert(s[r]); //������ָ����ָ�ı���
            max_len = max(max_len,r-l+1);
            }
            return max_len;
        }
};