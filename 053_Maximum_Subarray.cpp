#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> max_v;
        int max_so_far = 0;
        max_v.resize(nums.size());
        max_so_far=max_v[0]= nums[0];// > 0 ? nums[0] : 0;
        for(size_t i = 1; i < nums.size(); i++)
        {            
            max_v[i]=max(nums[i], max_v[i-1]+nums[i]);
            max_so_far = max(max_so_far, max_v[i]);
            cout<<i<<"#"<<max_v[i]<<endl;
        }
        return max_so_far;
    }
};
int main(int argc, char* argv[])
{
    vector<int> nums= {-2,1};
    Solution s;
    cout<<s.maxSubArray(nums);
}