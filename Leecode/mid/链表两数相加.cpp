#include<iostream>
using namespace std;

/*
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�
����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

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
        while(l1||l2){//�Ƿ���δ�����������
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(!head){// ��ͷ�ڵ��Ƿ�ֵ
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