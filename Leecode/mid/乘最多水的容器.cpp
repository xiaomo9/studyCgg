#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_result = 0;
        for(int l = 0,r=height.size()-1; l<r;){//×óÖ¸Õë
            max_result = max(max_result,(r-l)*min(height[r],height[l]));
            if(height[r]>height[l]) l++;
            else(r--);
            }
        return max_result;
    }
};