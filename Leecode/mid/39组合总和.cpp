#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates 
�п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ��
����������ǲ�ͬ�ġ� 

���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����
*/

class Solution {
public:
    vector<int> v1;
    int sum = 0;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return result;
    }
    void backtracking(vector<int>& canadidates, int target, int startindex){
        if(sum == target){
            result.push_back(v1);
            return;
        }
        if(sum > target) return;
        for(int i = startindex; i<canadidates.size(); i++){
            sum += canadidates[i];
            v1.push_back(canadidates[i]);
            backtracking(canadidates,target,i); //�ݹ�
            sum -= canadidates[i]; //����
            v1.pop_back();
        }
    }
};

