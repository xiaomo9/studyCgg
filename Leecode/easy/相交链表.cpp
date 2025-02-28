#include<iostream>
using namespace std;
#include<unordered_set>
/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
*/
struct ListNode
{
    ListNode(int x) //构造函数
    {
        this->val = x;
        this->Next = NULL;
    }
    int val;
    ListNode *Next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set_list;
        ListNode * temp = headA;
        while(temp != NULL)
        {
            set_list.insert(temp);
            temp = temp->Next;
        }
        temp = headB;
        while(temp != NULL)
        {
            if(set_list.count(temp))
            {
                return temp;
            }
            temp = temp->Next;
        }
        return NULL;
    }
};

int main()
{
    ListNode headA = ListNode(1);
    ListNode headB = ListNode(10);
    ListNode Node1 = ListNode(3);
    ListNode Node2 = ListNode(5);
    ListNode Node3 = ListNode(9);
    ListNode Node4 = ListNode(7);
    ListNode Node5 = ListNode(8);
    headA.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;
    headB.Next = &Node3;

    Solution s;
    ListNode *result;
    result = s.getIntersectionNode(&headA,&headB);
    cout << result->val << endl;
    system("pause");
    return 0;
}