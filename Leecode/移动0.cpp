/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

��ע�� �������ڲ���������������ԭ�ض�������в�����
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count1 = count(nums.begin(),nums.end(),0);
        for(int i = 0; i < count1; ++i)
        {
            for(int j = 0; j < nums.size()-i-1; j++)
            {
                if(nums[j] == 0) swap(nums[j], nums[j+1]);
            }
        }

    }
};

int main()
{
    vector<int> v;
    // v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    // v.push_back(2);
    v.push_back(1);

    Solution s;
    s.moveZeroes(v);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << endl;
    }
    system("pause");
}