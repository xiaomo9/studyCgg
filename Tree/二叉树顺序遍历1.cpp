# include<iostream>
using namespace std;

//定义树节点
struct Node
{
    string ch;
    Node *Lchlid;
    Node *Rchild;
    Node(string ch)
    {
        this->ch = ch;
        this->Lchlid = nullptr;
        this->Rchild = nullptr;
    }
};

// 遍历树节点(递归)
void printtree(Node *root)
{
    if(root == nullptr) return;

    // 先序遍历
    cout << root->ch << endl;
    // 递归
    printtree(root->Lchlid);
    printtree(root->Rchild);


}

void test()
{
    //创建各个结点
    Node *RootNode = new Node("A");
    Node *Node1 = new Node("B");
    Node *Node2 = new Node("C");
    Node *Node3 = new Node("D");
    Node *Node4 = new Node("E");
    Node *Node5 = new Node("F");
    Node *Node6 = new Node("G");
    Node *Node7 = new Node("H");

    RootNode->Lchlid = Node1;
    RootNode->Rchild = Node5;
    Node1->Rchild = Node2;
    Node2->Lchlid = Node3;
    Node2->Rchild = Node4;
    Node5->Rchild = Node6;
    Node6->Lchlid = Node7;

    printtree(RootNode);
}

int main()
{
    test();
    system("pause");
}
