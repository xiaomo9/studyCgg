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

//递归拷贝二叉树
Node* copytree(Node *root)
{
    if(root == NULL) return NULL;
    Node *Lchild = copytree(root->Lchild);
    Node *Rchild = copytree(root->Rchild);
    Node *newroot = new Node(root->ch);
    newroot->Lchild = Lchild;
    newroot->Rchild = Rchild;
    return newroot;
}

//释放堆区资源
void deletetree(Node *root)
{
    if(root == NULL) return;
    deletetree(root->Lchild);
    deletetree(root->Rchild);
    delete root;
    root = NULL;
}

// 遍历二叉树
void printtree(Node *root)
{
    if(root == NULL) return;
    cout << root->ch << endl;
    printtree(root->Lchild);
    printtree(root->Rchild);
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

    Node *newtree = copytree(&RootNode1);
    printtree(newtree);
    deletetree(newtree);
}


int main()
{
    test();
    system("pause");
}
