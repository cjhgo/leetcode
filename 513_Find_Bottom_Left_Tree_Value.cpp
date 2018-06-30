#include<climits>
#include<cmath>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode():left(NULL), right(NULL){}
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; 


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<int> record;
        q.push(root);
        int cnt = 0;
        int cur_level = 0;
        int null_cnt = 0;
        int level_cnt = 0;
        int max = -1;
        while(not q.empty())
        {
            TreeNode* x = q.front();
            if(x != NULL )
            {
                q.push(x->left);
                q.push(x->right);
                record.push_back(x->val);
            }
            else
            {
                record.push_back(INT_MAX);
                q.push(NULL);
                q.push(NULL);
                ++null_cnt;
            }                       
            q.pop();
            cnt++;
            level_cnt++;
            if(null_cnt == pow(2, cur_level))
                break;
            if(level_cnt == pow(2, cur_level))
            {
                ++cur_level;
                null_cnt = 0;
                level_cnt = 0;
            }
            
        }
        for(int i = 0; i < pow(2, i); i++)
        {
            int index = pow(2, cur_level-1) -1 + i;
            if(record[index] != INT_MAX)
            return record[index];
        }        
        return -1;
    }                
};

int main(int argc, const char* argv[])
{
    TreeNode root(2);
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(9);
    TreeNode d(1);
    TreeNode e(3);
    root.left = &d;
    root.right = &e;
    // d.left = &a;
    // d.right = &b;
    // e.right = &c;
    Solution s;
    cout<<s.findBottomLeftValue(&root);
}