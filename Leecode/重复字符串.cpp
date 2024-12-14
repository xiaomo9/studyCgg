#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int temp = 0;
        for(int i =0; i<nums.size(); ++i){
            if(nums[i] == 1){
                temp += 1;
                if(temp > max)
                {
                    max = temp;
                }
            }
            else{
                temp = 0;
            }
        }
        return max;
    }
};


int * add(int a, int b){
    int arr[] = {1,2,3,4};
    return arr;
}

int main()
{
    int *a  = add(10,20);

}