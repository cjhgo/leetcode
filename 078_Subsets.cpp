#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets2(vector<int>& nums) 
    {
        const size_t n = pow(2, nums.size());
        vector<vector<int>> res;
        bitset<64> flag;
        for(size_t i = 0; i < n; ++i )
        {
            vector<int> temp;
            flag=i;
            for(size_t j = 0;j<64;j++)
            {
                if(flag[j])
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        cout<<n<<"#"<<res.size()<<endl;
        return res;
    }
    
    void helper(vector<int>& nums, int cur, int from)
    {
        res.push_back({temp.begin(), temp.begin()+cur});
        for(int i = from; i < nums.size();i++)
        {
            if(i>from &&nums[i] == nums[i-1])continue; //this line is for subsetsWithDup
            temp[cur] = nums[i];
            helper(nums, cur+1, i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)     
    {
        sort(nums.begin(), nums.end());
        temp.resize(nums.size());
        helper(nums,0,0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
};
int main(int argc, char const *argv[])
{
    //vector<int> nums = {1,2,3,4,5,6,7,8};
    vector<int> nums;
    for(int i = 0; i < 16;i++)
    nums.push_back(i);
    Solution s;
    
    nums = {3,5,7,7,9};
    // nums = {1,2,2};
    for(auto e: s.subsets(nums))
    {
        for(auto x:e)
        cout<<x<<"\t";
        cout<<endl;
    }
    return 0;
}