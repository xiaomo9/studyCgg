#include<iostream>
using namespace std;
#include<vector>

/*
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�

����԰� �κ�˳�� ���ش𰸡�
*/


class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        backstracking(n,k,1);
        return result;
    }
    void backstracking(int n,int k,int startindex){
        if(v1.size() == k){
            result.push_back(v1);
            return;
        }
        for(int i = startindex;i<=n;i++){
            v1.push_back(i);//����ڵ�
            backstracking(n,k,startindex+1);//�ݹ����
            v1.pop_back();//���ݲ���
        }
    }
};