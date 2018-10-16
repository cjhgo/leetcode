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
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size() < 3) return {};
        if(count(nums.begin(), nums.end(), 0) == nums.size())
        return {{0,0,0}};
        unordered_map<int,int> values;
        for(auto it : nums)
        {
            values[it]++;
        }
        set<vector<int>>  result;
        for(size_t i = 0; i < nums.size()-1; i++)
        {
            for(size_t j = i+1; j < nums.size();j++)
            {
                int a = nums[i], b = nums[j], c = 0- a-b;    
                if(values.find(c) != values.end())
                {
                    if(c==a || c==b)
                    {
                        if( a == b)
                        {
                            //a==b==c,=0
                            if(values.at(c) < 3)
                            continue;
                        }
                        else
                        {
                            //a, b==c or b, a==c
                            if(values.at(c) < 2)
                            continue;
                        }
                    }
                    int temp[]={a,b,c};
                    sort(temp, temp+3);
                    result.insert({temp, temp+3});
                }
            }
        }        
        return {result.begin(), result.end()};
    }
    vector<vector<int>> threeSum1(vector<int>& nums) 
    {
        set<vector<int>>  result;
        if(nums.size() < 3) return {};
        if(count(nums.begin(), nums.end(), 0) == nums.size())
        return {{0,0,0}};
        sort(nums.begin(), nums.end());
        
        for(auto it = nums.begin(); it != (nums.end()-2); it++)
        {
            int a = *it;
            auto start = it+1;
            auto end = nums.end()-1;
            while(start < end)
            {
                int b = *start;
                int c= *end;
                if(a+b+c == 0)
                {
                    result.insert({a,b,c});
                    start++;
                    end--;
                }
                else if(a+b+c > 0)
                end--;
                else if(a+b+c < 0)
                start++;
            }
        }
        return {result.begin(), result.end()};
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums ={-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //{-1, 0, 1, 2, -1, -4};
    auto ret = sol.threeSum(nums);
    for(auto e: ret)
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    return 0;
}
