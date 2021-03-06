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
        int counter = 1;
        for(size_t i = 1; i < nums.size(); i++)
        {
            if( nums[i] != nums[counter-1])
            {
                //loop invariant
                //index: c-2,c-1,c,...,i-1,i
                //value: x  ,a  ,a,...,  a,b
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
    cout<<sol.removeDuplicates(nums)<<endl;
    for(auto e: nums)
    cout<<e<<"\t";
    return 0;
}