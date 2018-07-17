#include<queue>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur=root;
        TreeNode* pre=nullptr;
        
        while(true)    
        {
            pre=cur;
            if( cur->val > val)            
                cur = cur->left;
            else
                cur = cur->right;
            if( cur == NULL)
                break;
        }

        TreeNode* temp = new TreeNode(val);
        if(pre->val < val)
            pre->right=temp;
        else
            pre->left=temp;
        return root;
    }
};


void output_bst_by_level(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(not q.empty() )
    {
        TreeNode* cur = q.front();
        cout<<cur->val<<endl;
        q.pop();
        if( cur->left != NULL)
            q.push(cur->left);
        if( cur->right != NULL)
            q.push(cur->right);
    }
}
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode a(1);    
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(7);
    d.left=&b;
    d.right=&e;
    b.left=&a;
    b.right=&c;
    output_bst_by_level(&d);
    cout<<endl;
    output_bst_by_level( s.insertIntoBST(&d,5 ));
    return 0;
}
