#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
/*
����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ��
����԰� ����˳�� ���ش𰸡�

�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
    void backtracking(vector<int>& nums, int startindex){
        if(v1.size() > 1) {
            result.push_back(v1);
        }
        if(startindex >= nums.size()) return; // ������ڵ�����ݹ�
        unordered_set<int> set1;
        for(int i = startindex; i< nums.size(); i++){
            if(set1.find(nums[i])!=set1.end() || !v1.empty()&&nums[i] < v1.back()) continue; // �������ڸò��Ѿ��ù������ߴ�����ǰһ����С��������
            v1.push_back(nums[i]);
            set1.insert(nums[i]); //��¼���ù�����
            backtracking(nums,i+1); //�ݹ�
            v1.pop_back();//����
        }
    }
};