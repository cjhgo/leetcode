#include<iostream>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution 
{
public:
    void invert(TreeNode* root)
    {
        if(root == nullptr ) return;
        invert(root->left);
        invert(root->right);
        TreeNode* temp = root->left;
        root->left=root->right;
        root->right=temp;
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return  root;     
    }
};

int main(int argc, char const *argv[])
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left=&b;
    a.right=&c;
    c.left=&d;
    c.right=&e;
    Solution s;
    s.invertTree(&a);
    cout<<a.left->val<<endl<<a.right->val<<endl;
    cout<<c.left->val<<endl<<c.right->val<<endl;
    return 0;
}