#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>>  result;
        sort(nums.begin(), nums.end());
        
        for(auto it = nums.begin(); it != (nums.end()-2); it++)
        {
            set<int> need;
            for(auto it2= it+1; it2 != nums.end();it2++)
            {
                if(need.find(*it2) == need.end())
                {
                    need.insert(-*it-*it2);
                }
                else
                    result.insert({*it, *it2, 0-*it-*it2});
            }
        }
        return {result.begin(), result.end()};
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};//{-1, 0, 1, 2, -1, -4};
    auto ret = sol.threeSum(nums);
    for(auto e: ret)
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    return 0;
}
