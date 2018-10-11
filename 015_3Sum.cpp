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
    set<vector<int>> twoSum(vector<int>& nums, int index, bool& flag) 
    {
        set< vector<int>> ret;        
        size_t n = nums.size();
        vector<int> result;
        map<int,int> value_to_index;
        flag=false;
        int target = 0 - nums[index];
        for(int i = 0;i < n; i++)
        {
            if(i == index) continue;
            vector<int> result;
            int to_find = target-nums[i];
            auto res = value_to_index.find(to_find);
            
            if(res != value_to_index.end() )
            {   
                result.push_back(0-target);
                result.push_back(nums[i]);
                result.push_back(to_find);
                flag=true;
                sort(result.begin(), result.end());
                ret.insert(result);
            }
            value_to_index[nums[i]] = i;
        }        
        return ret;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>>  result;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            vector<int>temp;
            int target = 0 - *it;
            bool flag;
            auto ret = twoSum(nums, std::distance(nums.begin(), it), flag);
            if(flag)
            {
                result.insert(ret.begin(), ret.end());
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
