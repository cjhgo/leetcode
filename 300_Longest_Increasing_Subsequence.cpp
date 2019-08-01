#include"struct_define.h"
#include<iostream>
#include <algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
      if(nums.size() < 2) return nums.size();
      vector<int> dp(nums.size());
      dp[0]=1;
      for(int i = 1; i < nums.size(); i++)
      {
        int dpi = 1;
        for(int j = 0; j < i; j++)
        {
          if(nums[i] > nums[j])
          {
            if(dp[j]+1 > dpi) dpi = dp[j]+1;
          }
        }
        dp[i] = dpi;
      }

      return *std::max_element(dp.begin(),dp.end());
    }

};

int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> input = {4,10,4,3,8,9};
  //{2,2};
  //{10,9,2,5,3,7,101,18};
  std::cout<<sol.lengthOfLIS(input);
  return 0;
}