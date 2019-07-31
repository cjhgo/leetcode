#include"struct_define.h"
#include<iostream>
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
      
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> input = {10,9,2,5,3,7,101,18};
  std::cout<<sol.lengthOfLIS(input);
  return 0;
}