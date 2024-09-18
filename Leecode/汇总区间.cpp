#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> str;
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i+1 == nums.size() || nums[i] != nums[i+1]-1)
            {   
                string s = "";
                if(i==j){
                    s += to_string(nums[i]);
                    str.push_back(s);
                    j++;
                }
                else{
                    s = to_string(nums[j]) + "->";
                    s += to_string(nums[i]);
                    str.push_back(s);
                    j = i+1;
                }
            }
        }
        return str;
    }
};


int main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);
    Solution s;
    vector<string> s1 = s.summaryRanges(v);
    for(vector<string>::iterator itr=s1.begin() ; itr!=s1.end(); itr++)
    {
        cout << *itr << endl;
    }
    system("pause");
}