#include<iostream>
using namespace std;

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，
并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val): val(val),next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = NULL;
        ListNode *temp = head;
        while(l1||l2){//是否有未遍历完的数组
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(!head){// 看头节点是否赋值
                head = new ListNode(sum);
            }else{
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry){
            temp->next = new ListNode(1);
        }
        return head;
    }
};