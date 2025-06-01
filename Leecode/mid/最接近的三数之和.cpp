#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); 
        int add1 = INT_MAX/2 , min_d = INT_MAX/2, add2 = INT_MAX/2;
        for(int i = 0;i<nums.size()-2;++i){
            if(nums[i]+nums[i+1]+nums[i+2]>target){
                add1 = nums[i]+nums[i+1]+nums[i+2];
                break;
            }
            int l = i+1, r= nums.size()-1;
            int move = 0;
            while (l<r)
            {
                int add = nums[i] + nums[l] + nums[r];
                move = add-target;
                if(abs(add-target)<min_d){
                    min_d = abs(add-target);
                    add2 = add;
                }
                if(move > 0) r--;
                else if(move < 0) l++;
                else if(move == 0) return add;
            }
        }
        if(abs(add1-target)<min_d){
            return add1;
        }
        else return add2;
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> a = {2,3,8,9,10};
    int as = s.threeSumClosest(a,16);
    cout << as << endl;
    system("pause");
    return 0;
}