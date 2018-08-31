#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
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
};
int main(int argc, char const *argv[])
{
    //vector<int> nums = {1,2,3,4,5,6,7,8};
    vector<int> nums;
    for(int i = 0; i < 16;i++)
    nums.push_back(i);
    Solution s;
    
    for(auto e: s.subsets(nums))
    {
        for(auto x:e)
        cout<<x<<"\t";
        cout<<endl;
    }
    return 0;
}