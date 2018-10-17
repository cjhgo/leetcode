#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    int reversePairs(vector<int>& nums) 
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
