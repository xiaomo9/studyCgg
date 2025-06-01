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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len ++;
            temp = temp->next;
        }

        int num = len - n;
        if(num == 0) 
        {
            head = head->next; 
            return head;
        }
        ListNode *temp1 = head;
        while(num != 1){
            temp1 = temp1->next;
            num -- ;
        }
        temp1->next = temp1->next->next;

        return head;
    }
};

int main(){
    ListNode*head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    ListNode *re = s.removeNthFromEnd(head, 1);

    return 0;
}