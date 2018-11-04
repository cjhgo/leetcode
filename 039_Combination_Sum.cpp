#include<iostream>
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
        cout<<target<<":\t";
        for(auto e: nums)
        {
            cout<<e<<"\t";
        }
        cout<<endl<<endl;
        if( nums.size() >= 2)
        {  
            int a = nums[0];
            size_t quotient = target / a;
            
            for(size_t i = 0; i <= quotient; i++)
            {
                
                vector<int> temp(i, a);
                size_t new_target = target - (i*a);
                auto res = helper({nums.begin()+1, nums.end()}, new_target);
                if( new_target  == 0  )
                {
                    ret.push_back(temp);
                }
                else // new_target > 0
                {                
                    if(res.size() > 0)
                    {
                        for(auto e : res)
                        {
                            e.insert(e.end(),temp.begin(), temp.end());
                            ret.push_back(e);
                        }
                    }
                    else
                    {

                    }
                }
            }
        }
        else
        {
            if( nums[0] == target)
            return {{target}};
            else
            return {{}};
        }
        return ret;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ret{{}};
        for(auto e: helper(candidates, target))
        {
            if( accumulate(e.begin(), e.end(),0) == target)
            ret.push_back(e);
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums{2,3,6,7};
    auto r = sol.combinationSum(nums, 7);
    return 0;
}