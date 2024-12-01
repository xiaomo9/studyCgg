#include<iostream>
using namespace std;

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val): val(val), next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode *new_head = head->next;
        head->next = swapPairs(new_head->next); //迭代
        new_head->next = head;
        return new_head;
    }
};

