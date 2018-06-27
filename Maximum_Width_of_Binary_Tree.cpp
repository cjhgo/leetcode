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


TreeNode* construct_tree(int& index, vector<int> values)
{
    if(index >= values.size())
    return NULL;
    TreeNode* t = new TreeNode;
    t->val = values[index];
    ++index;
    t->left = construct_tree(index, values);
    ++index;
    t->right = construct_tree(index, values);
    return t;
}
TreeNode* construct_from_list(vector<int> values)
{
    TreeNode* x;
    int j = 0;
    while(j < values.size())
    {
        x = construct_tree(j , values);
    }
    return x;
}
void output_by_level(TreeNode*  root) 
{
        queue<TreeNode*> q;
        vector<int> record;
        q.push(root);
        int cnt = 0;
        int cur_level = 0;
        int null_cnt = 0;
        int level_cnt = 0;
        while(not q.empty())
        {
            TreeNode* x = q.front();
            if(x != NULL )
            {
                cout<<cur_level<<"#"<<cnt<<"#"<<x->val<<endl;
                q.push(x->left);
                q.push(x->right);
                record.push_back(1);
            }
            else
            {
                cout<<cur_level<<"#"<<cnt<<"#"<<"NULL"<<endl;
                record.push_back(0);
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
        cout<<endl<<cur_level<<endl<<endl;
        cout<<endl<<endl;
        int max = -1;
        for(int i = 0; i < cur_level; i++)
        {
            int begin = pow(2, i) -1;
            int end = pow(2, (i+1)) -2;
            int left,right;
            left=right= 0;

            for(int j = begin; j <= end; j++)
            {
                cout<<record[j];
                if(record[j] == 1)
                {
                    left = j;
                    break;
                }
                    
            }
            for(int k = end; k  >= begin; k--)
                if(record[k] == 1)
                {
                    right= k;
                    break;
                }
                    
            cout<<"#"<<begin<<"#"<<end<<"#"<<right-left<<endl;
            if(right - left > max)
                max = right - left;

        }
        cout<<"max is "<< max;
        cout<<endl<<endl;
        for(auto e : record)
        cout<<e<<endl;
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
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
                record.push_back(1);
            }
            else
            {
                record.push_back(0);
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
        
        for(int i = 0; i < cur_level; i++)
        {
            int begin = pow(2, i) -1;
            int end = pow(2, (i+1)) -2;
            int left,right;
            left=right= 0;

            for(int j = begin; j <= end; j++)
            {
                if(record[j] == 1)
                {
                    left = j;
                    break;
                }
                    
            }
            for(int k = end; k  >= begin; k--)
            {
                if(record[k] == 1)
                {
                    right= k;
                    break;
                }
            }       
            if(right - left+1 > max)
                max = right - left+1;

        }
        return max;
    }
};

int main(int argc, const char* argv[])
{
    TreeNode root(1);
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(9);
    TreeNode d(3);
    TreeNode e(2);
    root.left = &d;
    root.right = &e;
    d.left = &a;
    d.right = &b;
    e.right = &c;
    //output_by_level(&root);
    vector<int> values= {1,5,8,9,7,7,8};
    TreeNode * x = construct_from_list(values);
    cout<<endl;
    output_by_level(x);
}