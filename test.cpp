#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
/*
����һ�������ͷ�ڵ� head ��һ������ val ��
����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
*/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 1;
        int sum = 0;
        int len = colors.size();
        for(int i = 1; i<len+2; ++i){
            if(colors[i%len]==colors[(i-1)%len]){
                cnt = 1;
                continue;
            }
            cnt++;
            if(cnt>=3){
                sum++;
            }
        }
        return sum;
    }
};