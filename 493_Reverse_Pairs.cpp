#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:

    int helper(vector<int>& nums, size_t left, size_t right);
    {

    }
    int reverse(vector<int>& nums, size_t left, size_t right)
    {
        if(left+1 = right)
        {
            if(nums[left] > (int64_t)nums[right]*2)
            return 1;
            else
            return 0;
        }
        else
        {
            int middle = left+right/2;
            int left = reverse(nums, left, middle);
            int right = reverse(nums, middle+1, right);
            int both = helper(nums, left, right);
            return left+right+both;
        }

    }
    int reversePairs(vector<int>& nums) 
    {
        return reverse(nums, 0, nums.size()-1);
    }
    int reversePairs2(vector<int>& nums) 
    {
        int count = 0;
        for(size_t i = 0; i < nums.size()-1; i++)
        {
            for(size_t j = i+1; j < nums.size(); j++)
            {                
                int64_t a = nums[i], b = (int64_t)nums[j] * 2;
                if(a > b) count++;
            }
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums ={2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    //{2,4,3,5,1};
    Solution sol;
    cout<<sol.reversePairs(nums)<<endl;
    return 0;
}
