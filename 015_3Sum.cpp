#include<vector>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target, bool& flag) 
    {
        size_t n = nums.size();
        vector<int> result(2,0);
        map<int,int> value_to_index;
        flag=false;
        for(int i = 0;i < n; i++)
        {
            int to_find = target-nums[i];
            auto res = value_to_index.find(to_find);
            
            if(res != value_to_index.end() )
            {            
                result[0]=nums[i];
                result[1]=to_find;//value_to_index[to_find];
                flag=true;
                break;
            }
            value_to_index[nums[i]] = i;
        }        
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            vector<int> temp, temp2;
            int target = 0 - *it;
            temp2.insert(temp2.begin(), nums.begin(),it);
            temp2.insert(temp2.end(), it+1,nums.end());
            bool flag;
            auto ret = twoSum(temp2, target, flag);
            if(flag)
            {
                temp.push_back(*it);
                temp.insert(temp.end(), ret.begin(), ret.end());
                cout<<*it<<"\t"<<target<<"\t"<<"\t"<<ret[0]<<"\t"<<ret[1]<<endl;
                result.push_back(temp);
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto ret = sol.threeSum(nums);
    for(auto e: ret)
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    return 0;
}
