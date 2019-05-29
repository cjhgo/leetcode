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
          int ok = 0, pos=-1;
          for(int i = 0; i < right.size(); i++)
          {
            if(right[i] > nums[j])
            {
              ok = 1;
              pos = i;
              break;
            }
          }
          if(ok)
          {
            swap(nums[j],right[pos]);
            break;
          }else
          {
            right.push_back(nums[j]);
            nums.erase(nums.begin()+j);
          }
        }
        sort(right.begin(),right.end());
        nums.insert(nums.end(), right.begin(),right.end());
        for(auto e:nums)cout<<e;
        cout<<endl;
    }
    void Permuate(vector<int>& nums)
    {
      auto init = nums;
      while (true)
      {
        nextPermutation(nums);
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