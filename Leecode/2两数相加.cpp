#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int array = 0;
        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        while(l1 || l2){
            int a1 = l1 ? l1->val:0;
            int a2 = l2 ? l2->val:0;
            int sum = a1 + a2 + array;
            array = sum / 10;
            sum %= 10;
            if(!head){
                head = temp = new ListNode(sum);
            }else{
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(array){
            temp->next = new ListNode(array);
        }
        return head;
    }
};