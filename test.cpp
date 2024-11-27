#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
/*
给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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