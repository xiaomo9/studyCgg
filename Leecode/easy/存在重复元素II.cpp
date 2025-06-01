#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>
/*
����һ���������� nums ��һ������ k ���ж��������Ƿ�������� ��ͬ������ i �� j ��
���� nums[i] == nums[j] �� abs(i - j) <= k ��������ڣ����� true �����򣬷��� false ��
 */

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto p = mapp.find(nums[i]);
            if(p != mapp.end())
            {
                if(i - p->second <= k)
                {
                    return 1;
                }
                else
                {
                    mapp[nums[i]] = i;
                }
            }
            else
            {
                mapp[nums[i]] = i;
            }
        }
        return 0;
    }
};

int main()
{   
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(10);
    nums.push_back(50);
    nums.push_back(80);
    int a = 10;
    Solution s;
    cout << s.containsNearbyDuplicate(nums,a) << endl;
    system("pause");
}