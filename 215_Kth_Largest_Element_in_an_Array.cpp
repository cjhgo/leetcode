#include<iostream>
#include<algorithm>
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
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution sol;
    cout<<sol.findKthLargest(nums,4);
    return 0;
}