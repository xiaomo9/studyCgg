#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);

    cout << Solution().containsDuplicate(v) << endl;
    system("pause");

}