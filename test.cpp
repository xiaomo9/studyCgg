#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left+1 != right)
        {
            int mid = (right - left)/2 + left;
            if(nums[mid] <= target) left = mid;
            if(nums[mid] > target) right = mid;
        }
        if(nums[left]==target) return left;
        else return -1;
    }
};

int main()
{
    system("pause");
}