#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
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
    void allpath(TreeNode* root, string path, vector<string>&vs)
    {
        if(root == nullptr) return;
        path += to_string(root->val);
        if(root->left==nullptr && root->right==nullptr) 
        {
            vs.push_back(path);return;
        }
        path += "->";
        allpath(root->left,path,vs);
        allpath(root->right,path,vs);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        allpath(root,"", res);
        return res;
    }
};


int main(){
    Solution s;
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    vector<string>v = s.binaryTreePaths(&root);
    for(vector<string>:: iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << (*itr)<< endl;
    }
    system("pause");
}

