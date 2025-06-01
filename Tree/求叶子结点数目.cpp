#include<iostream>
using namespace std;

struct Node
{
    char ch;
    Node *Lchild;
    Node *Rchild;
    Node(char chs)
    {
        this->ch = chs;
        this->Lchild = NULL;
        this->Rchild = NULL;
    }
};

//递归求叶子节点个数
void leafnum(Node *root, int *num)
{
    if(root == NULL) return;
    if(root->Lchild == NULL && root->Rchild == NULL)
    {
        (*num) ++;
    }
    // 左子树叶子数
    leafnum(root->Lchild,num);
    // 右子树叶子数
    leafnum(root->Rchild,num);
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
    RootNode1.Rchild = &RootNode6;
    RootNode2.Rchild = &RootNode3;
    RootNode3.Lchild = &RootNode4;
    RootNode3.Rchild = &RootNode5;
    RootNode6.Rchild = &RootNode7;
    RootNode7.Lchild = &RootNode8;

    int num = 0;
    leafnum(&RootNode1,&num);
    cout << "叶子个数为：" << num << endl;

}


int main()
{
    test();
    system("pause");
}
