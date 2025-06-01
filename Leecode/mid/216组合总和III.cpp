#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
/*
�ҳ��������֮��Ϊ n �� k ��������ϣ�����������������

ֻʹ������1��9
ÿ������ ���ʹ��һ�� 
���� ���п��ܵ���Ч��ϵ��б� �����б��ܰ�����ͬ��������Σ���Ͽ������κ�˳�򷵻ء�
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return result;
    }
    void backtracking(int k,int n,int startindex){
        int sum = accumulate(v1.begin(),v1.end(),0);
        if(v1.size() == k&&sum == n){ //��ֹ����
            result.push_back(v1);
            return;
        }
        if(sum > n) return;
        for(int i = startindex;i<=9;i++){
            v1.push_back(i);
            backtracking(k,n,i+1);
            v1.pop_back();
        }
    }
};