
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
    void DFS(TreeNode* root, vector<TreeNode*>&path ,int index)
    {
      if(root == nullptr) return;


      path.resize(index+1);
      path[index]=root;
      if(root->val == qv)
      {
        ppath.insert(ppath.begin(),path.begin(),path.end());
      }
      if(root->val == pv)
      {
        qpath.insert(qpath.begin(),path.begin(),path.end());
      }            
      DFS(root->left, path,index+1);
      DFS(root->right, path,index+1);      

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        pv = p->val;
        qv = q->val;
        DFS(root,path,0);
        int minlen = std::min(qpath.size(),ppath.size());
        int i =  0;
        for(; i < minlen; i++)
        {
          if( ppath[i] != qpath[i])
          break;
        }
        return qpath[i-1];
    }
private:
  int pv,qv;
  
  vector<TreeNode*> ppath,qpath,path;    
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



