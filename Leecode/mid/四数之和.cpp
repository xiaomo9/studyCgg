#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target ��
�����ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] 
����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for(int i = 0;i<nums.size()-3;i++){ //�׸��ֵ�ѭ��
            if(i>0&&nums[i] == nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
                for(int j = i+1; j<n-2;j++){//�ڶ����ֵ�ѭ��
                    if(j-i>1&&nums[j]==nums[j-1]) continue;
                    if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                    if(nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
                    int l = j+1, r = n-1;
                    while(l<r){
                        if(nums[i]+nums[j]+nums[l]+nums[r]==target){
                            vector<int> v1;
                            v1.push_back(nums[i]);
                            v1.push_back(nums[j]);
                            v1.push_back(nums[l]);
                            v1.push_back(nums[r]);
                            result.push_back(v1);
                            l++;r--;
                            while(nums[l] == nums[l-1]){
                                l++;
                                if(l > r) break;
                                }
                            while(nums[r] == nums[r+1]) {
                                r--;
                                if(l>r) break;
                            }
                        }
                        else if(nums[i]+nums[j]+nums[l]+nums[r] > target) r--;
                        else if(nums[i]+nums[j]+nums[l]+nums[r] < target) l++;
                    }
                }
        }
        return result;
    }
};

int main(){
    vector<int> v2 = {1,0,-1,0,-2,2};
    Solution s;
    vector<vector<int>> a = s.fourSum(v2,0);
}