#include<iostream>
using namespace std;
#include<vector>

/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
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
        for(int i=0; i<s.size();++i){ //��ָ��
            for(int j = i; j<s.size();++j){
                if((j-i+1)>max_len&&is_huiwen(s,i,j)){// �ǻ��Ĵ�
                    max_len = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,max_len);
    }
};