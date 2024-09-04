#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int ingleNumber(vector<int>& nums) 
    {
        int flag = 0;
        for(int i : nums)
        {
            flag = flag ^ i; // 异或符号
        }
        return flag;
    }
};


int main()
{
    vector<int> v; 
    v.push_back(10);
    v.push_back(10);
    v.push_back(1);
    Solution s;
    int falg = s.ingleNumber(v);
    cout << "只存在一个的数字为：" << falg << endl;
    system("pause");
}