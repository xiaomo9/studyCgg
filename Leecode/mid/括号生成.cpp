#include<iostream>
using namespace std;
#include<vector>


/*
���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
*/

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        //�ݹ����������
        if(n<=0) return result;
        generate("",n,n);
        return result;
    }
    void generate(string s,int left, int right){
        if(left==0 &&right==0)
        {
            result.push_back(s);
            return;
        }
        if(left == right){
            // ������������һ�£���ʱֻ�ܲ��루
            generate(s+'(',left-1,right);
        }
        else if(left < right){
            //�������Ŷ��������ţ��������Ҷ�����
            if(left>0) generate(s+'(',left-1,right);
            generate(s+')',left,right-1);
        }
    }
};