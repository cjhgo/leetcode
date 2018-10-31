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
    int removeElement(vector<int>& nums, int val) 
    {
        int counter = 0;
        for(size_t i = 0; i < nums.size(); i++)
        {
            if( nums[i] != val)
            {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};    
    cout<<sol.removeElement(nums,2)<<endl;
    for(auto e: nums)
    cout<<e<<"\t";
    return 0;
}