#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        vector<int> right;
        for(int j = nums.size()-1; j >= 0; j--)
        {
          for(int i = nums.size()-1; i > j ; i--)
          {
            if(nums[i] > nums[j])
            {
              swap(nums[j],nums[i]);
              sort(nums.begin()+j+1, nums.end());
              return;
            }
          }
        }
        sort(nums.begin(),nums.end());        
    }
    void Permuate(vector<int>& nums)
    {
      auto init = nums;
      while (true)
      {
        nextPermutation(nums);
        for(auto e: nums)cout<<e;
        cout<<endl;
        if(nums == init)break;
      }      
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> nums{1,4,3,2};
  sol.nextPermutation(nums);
  nums={1,3,4,2};
  sol.nextPermutation(nums);
  nums={4,3,2,1};
  sol.nextPermutation(nums);

  cout<<endl;
  nums={1,2,3,4};
  sol.Permuate(nums);
  return 0;
}