#include<iostream>
using namespace std;
#include<vector>

/*
����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� 
���Ĵ������� s ���п��ܵķָ����
*/
class Solution {
public:
    vector<vector<string>> result;
    vector<string> v1;
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
    bool is_huiwen(string s){
        for(int i = 0, j= s.size()-1; i<j; i++,j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    void backtracking(string s, int startindex){
        if(startindex == s.size()){
            result.push_back(v1);
            return;
        }
        for(int i = startindex;i<s.size(); i++){
            string sub = s.substr(startindex,i-startindex+1);
            if(is_huiwen(sub)){
                v1.push_back(sub);
            }
            else return;
            backtracking(s,i+1);
            v1.pop_back();
        }
    }
};