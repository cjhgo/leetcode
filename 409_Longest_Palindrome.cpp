#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <unordered_map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 

class Solution 
{
public:
    int longestPalindrome(string s) 
    {
      unordered_map<char,int> charcnt;
      int cnt = 0;
      for(auto c : s)
      {
        charcnt[c]++;
      }
      bool addone=true;
      for(auto ele:charcnt)
      {
        if(ele.second % 2 != 0)
        {
          if(addone)
          {
            cnt += ele.second;
            addone=false;
          }
          else cnt += (ele.second-1);
        }
        else 
          cnt += ele.second;
      }
      return cnt;
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout<<sol.longestPalindrome("abccccdd");
  cout<<sol.longestPalindrome("bb");
  return 0;
}