#include<iostream>
using namespace std;
#include<vector>
#include<map>


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> v;
        for (int i:nums1) mp[i]++; // nums1中对应元素各个数
        for(int i: nums2)
        {
            if(mp.count(i))
            {
                if(mp[i]!=0)
                {
                v.push_back(i);
                mp[i]--;
                }
            }
        }
        return v;
    }
};