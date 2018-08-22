#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        map<int,int> count;
        for(auto e: nums)
            count[e]++;
        int i = 0;
        for(auto e: count)
        {
            for(int j = 0; j < e.second; j++)
                nums[i+j]=e.first;
            i += e.second;
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(auto e: nums)
    cout<<e<<endl;
    return 0;
}
