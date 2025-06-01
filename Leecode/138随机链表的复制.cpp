#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


struct ListNode
{
    int val;
    ListNode* next;
    ListNode* random;
    ListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    ListNode* copyRandomList(ListNode* head) {
        ListNode* temp = head;
        ListNode* new_head = new ListNode(head->val);
        ListNode* new_temp = new_head;
        unordered_map<ListNode*, ListNode*> node_set;
        if(head == nullptr) return new_head;
        while(temp != nullptr){
            if(node_set.count(temp->random)){
                new_temp->random = node_set[temp->random]; 
            }
            else{
                new_temp->random = new ListNode(temp->random->val);
                node_set[temp->random] = new_temp->random;
            }
            if(node_set.count(temp->next)){
                new_temp->next = node_set[temp->next];
            }
            else{
                new_temp->next = new ListNode(temp->next->val);
                node_set[temp->next] = new_temp->next;
            }
            temp = temp->next;
            new_temp = new_temp->next;
        }
        return new_head;
    }
};
