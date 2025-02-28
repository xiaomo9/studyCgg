#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prediff = 0;
        int curdiff = 0;
        int result = 1;
        for(int i = 0;i<nums.size()-1;i++){
            curdiff = nums[i+1] - nums[i];
            if((prediff <= 0&&curdiff >0)||(prediff >= 0 &&curdiff<0)){
                result ++;
                prediff = curdiff;
            }
        }
        return result;
    }
};