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
    int searchInsert(vector<int>& nums, int target) 
    {
        size_t i = 0;
        for(; i < nums.size();i++)
        {
            if( nums[i] == target)
            return i;
            else if( nums[i] < target)
            continue;
            else if( nums[i] > target)
            return i-1;

        }
        return i;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    cout<<sol.searchInsert(nums,7);
    return 0;
}