#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int res=-1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            int j = i+1;
            if(nums[j] == nums[i])
            {
                res = nums[i];
                break;
            }
        }    
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={3,1,3,4,2};
    Solution s;
    cout<<s.findDuplicate(nums);
    return 0;
}
