#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ� 
�Ӽ�
���ݼ�����

�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> v1;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return result; 
    }
    void backtracking(vector<int>& nums,int startindex){
        result.push_back(v1);
        if(startindex == nums.size()) return;
        for(int i = startindex; i < nums.size(); i++){
            v1.push_back(nums[i]);
            backtracking(nums,i+1);
            v1.pop_back();
            while(i<nums.size()-1 && nums[i]==nums[i+1]){ // �����ظ�Ԫ�أ��Ҳ�Ӱ����һ������ѭ��
                i++;
            }
        }
    }

};


int main(){
    Solution s;
    vector<int> v = {1,2,2};
    s.subsetsWithDup(v);
}