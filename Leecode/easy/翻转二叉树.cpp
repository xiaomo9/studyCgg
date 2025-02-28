#include<iostream>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *Ltree;
    TreeNode *Rtree;
    TreeNode(int val1)
    {
        this->val = val1;
        this->Ltree = nullptr;
        this->Rtree = nullptr;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        invertTree(root->Ltree);
        invertTree(root->Rtree);
        TreeNode *temp = root->Ltree;
        root->Ltree = root->Rtree;
        root->Rtree = temp;
        return root;
    }
};

void printtree(TreeNode *root)
{
    if(root==nullptr) return;
    cout << root->val << endl;
    printtree(root->Ltree);
    printtree(root->Rtree);
}

int main(){
    Solution s;
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);

    root.Ltree = &node1;
    root.Rtree = &node2;
    node2.Ltree = &node3;
    node2.Rtree = &node4;
    printtree(&root);
    s.invertTree(&root);
    printtree(&root);
    system("pause");
}

