#include<iostream>
using namespace std;
#include<vector>
//  * Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   // 三种树的构造方式
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int nodenum = 0;
        nodenum = countNodes(root->left) + countNodes(root->right);
        return nodenum + 1;
    }
};

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    Solution s;
    int deep = s.countNodes(&root);
    cout << "最小深度为：" << deep << endl;
    system("pause");
}