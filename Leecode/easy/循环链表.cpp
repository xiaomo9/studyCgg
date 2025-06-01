#include<iostream>
using namespace std;
#include<unordered_set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
    /* data */
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set_list;
        ListNode *temp = head;
        while(temp != NULL){
            if(set_list.count(temp)){
                return true;
            }
            set_list.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};