#include<iostream>
using namespace std;

struct  Node
{
    char ch;
    Node *Lchild;
    Node *Rchlid;
    // 构造函数
    Node(char str)
    {
        this->ch = str;
        this->Lchild = NULL;
        this->Rchlid = NULL;
    }
};

//递归遍历树
void printftree(Node *root)
{
    if(root == NULL) return;
    // 中序遍历
    printftree(root->Lchild);
    cout << root->ch << endl;
    printftree(root->Rchlid);
}

void test()
{
    Node RootNode1('A');
    Node RootNode2('B');
    Node RootNode3('C');
    Node RootNode4('D');
    Node RootNode5('E');
    Node RootNode6('F');
    Node RootNode7('G');
    Node RootNode8('H');

    RootNode1.Lchild = &RootNode2;
    RootNode1.Rchlid = &RootNode6;
    RootNode2.Rchlid = &RootNode3;
    RootNode3.Lchild = &RootNode4;
    RootNode3.Rchlid = &RootNode5;
    RootNode6.Rchlid = &RootNode7;
    RootNode7.Lchild = &RootNode8;

    printftree(&RootNode1);
}

int main()
{
    test();
    system("pause");
}