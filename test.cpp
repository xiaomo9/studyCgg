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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i = 0; i<nums1.size(); ++i){
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            for(;it!=nums2.end();it++){
                if(nums1[i]<*it){
                    result.push_back(*it);
                    break;
                }
            }
            if(it==nums2.end()) result.push_back(-1);
        }
        return result;
    }
};