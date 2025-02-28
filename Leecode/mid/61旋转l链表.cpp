#include<iostream>
using namespace std;
#include<vector>

//定义链表Node节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
};


class Solution {
public:
    int count_len(ListNode* head){
        ListNode* temp = head;
        int lenn = 1;
        while(temp->next != nullptr){
            lenn ++;
            temp = temp->next;
        }
        return lenn;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr ||head->next==nullptr){
            return head;
        }
        int longs = count_len(head);
        k = k % longs;
        for(int i = 0; i < k; i++){
            ListNode *temp = head;
            while(temp->next->next !=nullptr){
                temp = temp->next;
            }
            temp->next->next = head;
            head = temp->next;
            temp->next = nullptr;
        }
        return head;
    }
};