#include<iostream>
using namespace std;
#include<vector>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int nums){
        this->val = nums;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //��ȡ������
        int len = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            len ++;
            temp = temp->next;
        }
        if(n==len){ //ɾ���׸�Ԫ��
            head = head->next;
            return head;
        }
        ListNode *temp1 = head;
        for(int i = 1; i<len-n; i++)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        return head;
    }
};
