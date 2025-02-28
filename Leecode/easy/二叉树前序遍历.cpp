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
    void preorder(TreeNode* root,vector<int> &v) // 引用的方法对容器进去修改
    {
        if(root==nullptr) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
        
    }
};