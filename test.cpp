#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

/*
����һ�������ͷ�ڵ� head ��һ������ val ��
����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        vector<string> result;
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,int> map1;
        for(int i = 0; i<score.size(); ++i){
            map1[temp[i]] = i+1;
        }
        for(int k : score){
            if(map1[k]==1) result.push_back("Gold Medal");
            else if(map1[k]==2) result.push_back("Silver Medal");
            else if(map1[k]==3) result.push_back("Bronze Medal");
            else result.push_back(to_string(map1[k]));
        }
        return result;
    }
};


int main()
{
    vector<string> s1 = {"Hello","Alaska","Dad","Peace"};
    Solution s;
    system("pause");
    return 0;
}