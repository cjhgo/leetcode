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
    int change(int amount, vector<int>& coins) 
    {
      int n = coins.size();
      int dp[n+1][amount+1];
      vector<int> k_i(n);
      
      for(int i = 0; i <=n; i++)
      dp[i][0] = 1;
      for(int i = 0; i <= amount; i++)
      dp[0][i] = 0;
      dp[0][0]=1;

      for(int i = 1; i <= n; i++)
      for(int j = 1; j <= amount; j++)
      {
        int temp = 0;
        for(int k = 0; k <=  j/coins[i-1];k++)
        {
          int temp2 = j - k*coins[i-1];
          temp += dp[i-1][temp2];
        }
        dp[i][j] = temp;
      }
      return dp[n][amount];
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> coins = {1,2,5};
  cout<<sol.change(5,coins);
  return 0;
}