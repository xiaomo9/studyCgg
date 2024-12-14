#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*\
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 
且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // 先将数组升序排列
        vector<vector<int>> result;
        for(int k = 0;k<nums.size()-2;++k){
            if(k>0&&nums[k]==nums[k-1]) continue;
            if(nums[k]>0) break;//如果最左值大于零，那三个数必不能相加为0
            int l= k+1, r = nums.size()-1;
            while(l<r){
                int temp = nums[k]+nums[l]+nums[r];
                if(temp > 0) r--;
                else if(temp < 0) l++;
                else if(temp==0){
                    vector<int> v1;
                    v1.push_back(nums[k]);
                    v1.push_back(nums[l]);
                    v1.push_back(nums[r]);
                    result.push_back(v1);
                    l++;r--;
                    while(l>r && nums[l]==nums[l-1]) l++; // 防止重复记录相同组合
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> sampel = {0,0,0,0};
    vector<vector<int>> re = s.threeSum(sampel);
    for(auto a : re){
        for(auto b : a){
            cout << b <<endl;
        }
        cout << "\n" <<endl;
    }
    system("pause");
    return 0;
}