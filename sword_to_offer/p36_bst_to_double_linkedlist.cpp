


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
    bool Conv2(TreeNode* root, TreeNode*& head, TreeNode*& tail)
    {
      head = tail = root;
      if( root == nullptr)
      {
        // head=tail=nullptr;
        return false;
      }else 
      {
        
        TreeNode *lefthead=nullptr,*lefttail=nullptr;
        if (Conv2(root->left,lefthead, lefttail))
        {
          head = lefthead;
          lefttail->right = root;
          root->left = lefttail;
        }
        TreeNode *righthead=nullptr, *righttail=nullptr;
        if (Conv2(root->right, righthead, righttail))
        {
          tail = righttail;
          root->right = righthead;
          righthead->left = root;          
        }
        return true;
      }
    }
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
        Conv2(pRootOfTree, head, tail);
        return head;
    }
};