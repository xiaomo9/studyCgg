#include<iostream>
using namespace std;

/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
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
        head->next = swapPairs(new_head->next); //����
        new_head->next = head;
        return new_head;
    }
};

