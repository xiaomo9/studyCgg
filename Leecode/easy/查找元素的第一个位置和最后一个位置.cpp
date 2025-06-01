/*
����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target��
�����ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨���������
*/
#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int left1 = -1;
        int left2 = 0;
        int right1 = nums.size() - 1;
        int right2 = nums.size();
        vector<int> v_temp;
        v_temp.push_back(-1); v_temp.push_back(-1);
        if(nums.size()==0) return v_temp;
        while(left1+1 != right1)
        {
            int mid = (right1 - left1)/2 + left1;
            if(nums[mid] >= target) right1 = mid;
            else left1 = mid;
        }
        while(left2+1 != right2)
        {
            int mid = (right2 - left2)/2 + left2;
            if(nums[mid]<= target) left2 = mid;
            else right2 = mid;
        }
        
        if(nums[right1] == target)  v.push_back(right1);
        else v.push_back(-1);
        if(nums[left2] == target) v.push_back(left2);
        else v.push_back(-1);
        return v;
    }

};