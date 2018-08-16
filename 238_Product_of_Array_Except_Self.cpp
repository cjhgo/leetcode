#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        size_t n = nums.size();
        vector<int> res(n,1);
        int left=1, right=1;
        for(size_t i = 0; i < n; i++)
        {
            res[i] *= left;
            res[n-1-i] *= right;
            left *= nums[i];
            right *= nums[n-1-i];
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
