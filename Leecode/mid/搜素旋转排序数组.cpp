#include<iostream>
using namespace std;
#include<vector>

/*
局部排序的二分查找法
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r) >> 1; //右移除2
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){//左侧是有序数列
                (nums[l]<=target&&nums[mid]>=target) ? r = mid-1 : l = mid + 1;                
            }
            else{//右侧是有序数列
                (nums[mid]<=target&&nums[r]>=target) ? l = mid + 1 : r = mid - 1;
            }
        }
        return -1;
    }
};
