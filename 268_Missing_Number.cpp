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
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum = 0;
        for(auto e : nums)
        {
            sum += e;
        }
        int expect_sum = (0 + nums.size())*(nums.size() +1)/2;
        return expect_sum - sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<sol.missingNumber(nums);
    return 0;
}