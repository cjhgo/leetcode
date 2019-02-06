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
    bool isIdentical(TreeNode* s, TreeNode* t)
    {
        if( s==nullptr and t==nullptr)
            return true;
        else if( s!=nullptr and t!=nullptr)
        {
            if(s->val == t->val and (isIdentical(s->left, t->left) and isIdentical(s->right, t->right) ) )
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if( s==nullptr and t==nullptr)
            return true;
        else if( s!=nullptr and t!=nullptr)
        {
            if( isIdentical(s, t))
                return true;
            else
                return isSubtree(s->left, t) or isSubtree(s->right, t);                
        }
        else
            return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;    
    return 0;
}