#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<iterator>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums ={-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //{-1, 0, 1, 2, -1, -4};
    auto ret = sol.fourSum(nums,0);
    for(auto e: ret)
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    return 0;
}
