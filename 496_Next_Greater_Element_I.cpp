#include<iostream>
#include<vector>
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
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
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
