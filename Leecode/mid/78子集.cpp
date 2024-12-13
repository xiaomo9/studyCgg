#include<iostream>
using namespace std;
#include<vector>

/*

����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ�
�Ӽ�
���ݼ�����

�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
*/

class Solution {
public:
    vector<int> v1;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
    void backtracking(vector<int>& nums,int startindex){
        result.push_back(v1);
        if(startindex == nums.size()){
            return;
        }
        for(int i = startindex; i< nums.size(); i++){
            v1.push_back(nums[i]);
            backtracking(nums,i+1);
            v1.pop_back();
        }
    }
};