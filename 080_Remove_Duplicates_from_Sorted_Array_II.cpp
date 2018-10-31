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
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() < 2) return nums.size();
        int counter = 2, cnt=0;
        for(size_t i = 2; i < nums.size(); i++)
        {
            if( nums[i] != nums[counter-2])
            {
                nums[counter] = nums[2];
                counter++;
            }
        }
        return counter;
    }
    int removeDuplicates2(vector<int>& nums) 
    {
        if(nums.size() < 2) return nums.size();
        int counter = 1, cnt=0;
        for(size_t i = 1; i < nums.size(); i++)
        {
            if( nums[i] != nums[i-1])
            {
                nums[counter] = nums[i];
                counter++;
                cnt=0;
            }
            else//nums[i] == nums[]
            {
                ++cnt;
                nums[counter] = nums[i];
                if( cnt < 2)
                counter++;
            }
                
        }
        return counter;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    //{0,0,1,1,1,2,2,3,3,4};    
    cout<<sol.removeDuplicates(nums)<<endl;
    for(auto e: nums)
    cout<<e<<"\t";
    return 0;
}