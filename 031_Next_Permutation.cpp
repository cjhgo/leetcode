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
    void nextPermutation2(vector<int>& nums) 
    {
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
    void nextPermutation(vector<int>& nums) 
    {
        int j = nums.size()-1;
        while ( j >= 1 && nums[j] <= nums[j-1])
        {
          j--;
        }
        if( j >= 1)
        {
          int k = nums.size() - 1;
          while (nums[k] <= nums[j-1])
          {
            k--;
          }          
          swap(nums[k], nums[j-1]);          
        }
        sort(nums.begin()+j, nums.end());   
        for(auto e: nums)cout<<e;
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
  nums={1,5,1};
  sol.nextPermutation(nums);  
  nums={5,7,8,2,3,1,9,6};
  sol.nextPermutation(nums);


  cout<<endl;
  nums={1,2,3,4};
  sol.Permuate(nums);
  return 0;
}