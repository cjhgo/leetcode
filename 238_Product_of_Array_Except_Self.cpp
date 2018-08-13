#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = 1;
            for(int j = 0; j < nums.size(); j++)
            {
                if( j != i)
                {
                    temp *= nums[j];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4 };
    Solution s;
    for(auto e: s.productExceptSelf(nums))
    {
        cout<<e<<endl;
    }
    return 0;
}
