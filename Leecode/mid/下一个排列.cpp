#include<iostream>
using namespace std;
#include<vector>

/*
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
 下一个排列 就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        for(int j = len-1;j>0;j--){ //找到第一个后大于前的索引
            if(nums[j]>nums[j-1]){
                i = j;break;
            }
        }
        if(i == 0){
            for(int l=i,r=len-1;l<r;l++,r--){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
        }
        return;
        }
        for(int j = len-1;j>i-1;j--){//从后往前找第一个大于nums[i-1]的索引
            if(nums[j]>nums[i-1]){
                int temp = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = temp;
                break;
            }
        }
        for(int l=i,r=len-1;l<r;l++,r--){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> v1 = {3,2,1};
    s.nextPermutation(v1);
}