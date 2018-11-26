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
    int singleNumber(vector<int>& nums) 
    {
        int64_t flag=0;
        for(auto e : nums)    
            flag ^= e;
        return flag;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {4,1,2,1,2};
    Solution sol;
    cout<<sol.singleNumber(nums);
    return 0;
}