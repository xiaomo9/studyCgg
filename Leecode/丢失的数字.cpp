#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

/*
����һ������ [0, n] �� n ���������� nums ���ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i =1; i<nums.size+1; i++)
        {
            auto itr = find(nums.begin(), nums.end(), i);
            if(itr == nums.end()) return i;
        }
        return 0;
    }
};