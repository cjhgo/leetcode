#include "struct_define.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 

class Solution 
{
 public:
  vector<int> pre_, vin_;

  TreeNode* helper(int pre_index,int vin_index, int len)
  {
    cout<<pre_index<<"\t"<<vin_index<<"\t"<<len<<endl;

    TreeNode* ret = nullptr;
    if( len == 0)
      return ret;
    else if (len == 1)
    {
      ret = new TreeNode(pre_[pre_index]);
    }      
    else
    {
      ret = new TreeNode(pre_[pre_index]);
      int i = 0;
      for(; i < len; i++)
      {
        if(vin_[vin_index+i] == pre_[pre_index])
        {
          break;
        }
      }
      int leftlen = i, rightlen = len-i-1;
      int left_pindex = pre_index+1, right_pindex = pre_index+leftlen+1;
      int left_vindex = vin_index, right_vindex = vin_index+i+1;
      ret->left = helper(left_pindex, left_vindex, leftlen);
      ret->right = helper(right_pindex, right_vindex, rightlen);
    }
    
    return ret;
  }
  TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
  {

    pre_ = pre;
    vin_ = vin;
    return helper(0,0, pre_.size());
  }
};


int main(int argc, char const *argv[])
{
  vector<int> pre = {1,2,3,4,5,6,7}, vin = {3,2,4,1,6,5,7};
  Solution sol;
  printTree(sol.reConstructBinaryTree(pre, vin));
  return 0;
}