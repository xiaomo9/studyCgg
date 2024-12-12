#include<iostream>
using namespace std;
#include<vector>

/*
�ֲ�����Ķ��ֲ��ҷ�
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r) >> 1; //���Ƴ�2
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){//�������������
                (nums[l]<=target&&nums[mid]>=target) ? r = mid-1 : l = mid + 1;                
            }
            else{//�Ҳ�����������
                (nums[mid]<=target&&nums[r]>=target) ? l = mid + 1 : r = mid - 1;
            }
        }
        return -1;
    }
};
