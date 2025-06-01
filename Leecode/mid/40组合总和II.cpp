#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ��
�ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��

ע�⣺�⼯���ܰ����ظ�����ϡ� (�����л�����ظ�������)
*/


class Solution {
public:
    vector<vector<int>> result;
    vector<int> v1;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return result;
    }

    void backtracking(vector<int>& candidates, int target,int startindex){
        if(sum==target){
            result.push_back(v1);
            return;
        }
        if(sum > target) return;
        for(int i = startindex;i<candidates.size();i++){
            v1.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates,target,i+1);
            v1.pop_back();
            sum-=candidates[i];
            while(candidates[i]==candidates[i+1]&&i<candidates.size()){
                i++;
            }
        }
    }
};