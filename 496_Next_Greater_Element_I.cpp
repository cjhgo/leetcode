#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution 
{
public:
    vector<int> nextGreaterElement2(vector<int>& findNums, vector<int>& nums) 
    {
        map<int,int> value_to_pos;
        size_t nsize = nums.size();
        for(size_t i = 0; i < nsize;i++)
        {
            value_to_pos[ nums[i] ] = i;
        }
        vector<int> res;        
        for(auto e: findNums)
        {
            int pos = value_to_pos[e];
            for(pos++;pos < nsize;pos++)
            {
                if( nums[pos] > e)
                {
                    res.push_back(nums[pos]);
                    break;
                }                
            }    
            if( pos == nsize)res.push_back(-1);
        }
        return res;       
    }
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        map<int,int> value_to_nge;
        stack<int> mystack;
        for(auto e : nums)
        {
            while( mystack.size() > 0 and mystack.top() < e)
            {
                value_to_nge[mystack.top()] = e;
                mystack.pop();
            }
            mystack.push(e);
        }
        vector<int> res;        
        for(auto e: findNums)
        {
            res.push_back( value_to_nge.count(e) > 0 ? value_to_nge[e] : -1 );
        }
        return res;       
    }
};    
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> findNums{4,1,2}, nums{1,3,4,2};
    for(auto e: sol.nextGreaterElement(findNums, nums))
    {
        cout<<e<<"\t";
    }
    return 0;
}
