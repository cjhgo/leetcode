
#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 


class Solution {
public:

    void helper(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
      if(root == nullptr) return;
      if( p->val < root->val && q->val < root->val)
      {
        helper(root->left, p,q);
      }
      else if( p->val > root->val && q->val > root->val)
      {
        helper(root->right, p,q);
      }
      else 
        res = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
      res = nullptr;
      helper(root, p,q);
      if(res )std::cout<<res->val;
      return res;
    }
private:
    TreeNode* res;
};

int main(int argc, char const *argv[])
{
  Solution sol;
  TreeNode n6(6),n2(2),n8(8),n0(0),n4(4),n3(3),n5(5),n7(7),n9(9);

  n6.left = &n2;
  n6.right = &n8;
  n2.left = &n0;
  n2.right = &n4;
  n8.left = &n7;
  n8.right = &n9;
  n4.left = &n3;
  n4.right= &n5;

  
  
  sol.lowestCommonAncestor(&n6,&n2,&n4);
  return 0;
}



