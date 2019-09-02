


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void Conv(TreeNode* root, TreeNode*& head, TreeNode*& tail)
    {
      if(root == nullptr)
      {
        head=tail=root;
        return;
      }
      if(root->left != nullptr)
      {
        TreeNode *lefthead=nullptr, *leftail= nullptr;
        TreeNode *left = root->left;
        Conv(left, lefthead,leftail);

        leftail->right = root;
        root->left = leftail;
        head = lefthead;
      }else
      {
        head=root;
      }

      if( root->right != nullptr)
      {
        TreeNode *righthead=nullptr, *righttail=nullptr;
        TreeNode* right = root->right;
        Conv(right,righthead,righttail);
        righthead->left = root;
        root->right = righthead;
        tail = righttail;
      }else
      {
        tail = root;
      }
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* head=nullptr, *tail = nullptr;
        Conv(pRootOfTree, head, tail);
        return head;
    }
};