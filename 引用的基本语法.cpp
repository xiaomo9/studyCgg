#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* node;
    ListNode(int num) : val(num),node(nullptr){}
};

int main()
{
    //给一个变量取别名
    int a = 10;
    int &b = a;//a的别名为b
    cout << "a= " << a << "  b = " << b << endl;

    b = 100;
    cout << "a= " << a << "  b = " << b << endl;


    system("pause");
    return 0;
}