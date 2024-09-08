# include<iostream>
using namespace std;

//�������ڵ�
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

// �������ڵ�(�ݹ�)
void printtree(Node *root)
{
    if(root == nullptr) return;

    // �������
    cout << root->ch << endl;
    // �ݹ�
    printtree(root->Lchlid);
    printtree(root->Rchild);


}

void test()
{
    //�����������
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
