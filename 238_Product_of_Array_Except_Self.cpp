#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        int product = 1;
        for(auto e: nums)
        {
            product *= e;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = product / (nums[i] == 0 ? 1 : nums[i]);
            res.push_back(temp);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4 };
    Solution s;
    for(auto e: s.productExceptSelf(nums))
    {
        cout<<e<<endl;
    }
    return 0;
}
