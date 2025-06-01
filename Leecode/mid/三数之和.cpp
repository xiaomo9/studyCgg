#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*\
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k 
�� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 �����㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // �Ƚ�������������
        vector<vector<int>> result;
        for(int k = 0;k<nums.size()-2;++k){
            if(k>0&&nums[k]==nums[k-1]) continue;
            if(nums[k]>0) break;//�������ֵ�����㣬���������ز������Ϊ0
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
                    while(l>r && nums[l]==nums[l-1]) l++; // ��ֹ�ظ���¼��ͬ���
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