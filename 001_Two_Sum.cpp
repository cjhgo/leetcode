#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        size_t n = nums.size();
        vector<int> res(2,0);
        int i,j;
        for(i = 0;i < n; i++)
        {
            for( j = 0;j < n; j++)
            {
                if(j!=i and nums[i]+nums[j] == target)
                {
                    res[0]=i;
                    res[1]=j;
                    break;
                }
            }
        }        
        return res;
    }
    vector<int> twoSum2(vector<int>& nums, int target) 
    {
        size_t n = nums.size();
        vector<int> result(2,0);
        int i;
        for(i = 0;i < n; i++)
        {
            int to_find = target-nums[i];
            cout<<to_find<<endl;
            auto res = find(nums.begin(),nums.end(), target-nums[i]);
            auto index = distance(nums.begin(), res);
            if(res != nums.end() and index != i)
            {
                
                result[0]=i;
                result[1]=index;
                cout<<*res<<"\t"<<i<<distance(nums.begin(), res)<<endl;
                break;
            }
        }        
        return result;
    }

};
int main(int argc, char const *argv[])
{
    vector<int> nums={3,2,4};//{2,7,11,15};
    Solution s;
    for(auto e : s.twoSum(nums, 6))
    {
        cout<<e<<"\t";
    }
    return 0;
}
