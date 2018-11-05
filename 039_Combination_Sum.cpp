#include<iostream>
#include<set>
#include<numeric>
#include<vector>
#include<string>
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
    vector<vector<int>> helper(vector<int> nums, int target)
    {    
        vector<vector<int>> ret{{}};
        int a = nums[0];
        size_t quotient = target / a;
        
        for(size_t i = 0; i <= quotient; i++)
        {            
            vector<int> temp(i, a);            
            if( nums.size() > 1)
            {
                size_t new_target = target - (i*a);
                auto res = helper({nums.begin()+1, nums.end()}, new_target);
                for(auto e : res)
                {
                    e.insert(e.end(),temp.begin(), temp.end());
                    ret.push_back(e);
                }
            }
            else
                ret.push_back(temp);

        }        
        return ret;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        set<vector<int>> ret;
        for(auto e: helper(candidates, target))
        {
            if( accumulate(e.begin(), e.end(),0) == target)
            {
                ret.insert(e);
            }            
        }
        return {ret.begin(), ret.end()};
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums{2,3,6,7};
    auto r = sol.combinationSum(nums, 7);
    for(auto x : r)
    {
        for(auto xx: x)
        cout<<xx<<"\t";
        cout<<endl;
    }        
    cout<<r.size()<<endl;
    return 0;
}