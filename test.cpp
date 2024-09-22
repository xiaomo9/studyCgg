#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i = 0; i<nums1.size(); i++)
        {
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end())
            {
                
                
            }
        }
        return v;
    }
};

int main()
{
    system("pause");
}