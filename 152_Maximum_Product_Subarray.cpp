#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        vector<int> max_v, min_v;
        max_v.resize(nums.size());
        min_v.resize(nums.size());
        max_v[0]=min_v[0]=nums[0];
        int res = max_v[0];
        for(size_t i = 1; i < nums.size(); i++)
        {
            max_v[i]=min_v[i]=nums[i];
            if(nums[i] > 0 )
            {
                max_v[i] = max(max_v[i], max_v[i-1]*nums[i]);
                min_v[i] = min(min_v[i], min_v[i-1]*nums[i]);
            }
            else
            {
                max_v[i] = max(max_v[i], min_v[i-1]*nums[i]);
                min_v[i] = min(min_v[i], max_v[i-1]*nums[i]);
            }
            res = max(max_v[i], res);
        }
        return res;
    }
};
int main(int argc, char* argv[])
{
    vector<int> nums= {2,3,-2,4};
    Solution s;
    cout<<s.maxProduct(nums);
}