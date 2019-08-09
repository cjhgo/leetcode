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
    }//160ms
    int change2(int amount, vector<int>& coins) 
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
        dp[i][j] = dp[i-1][j];
        if( j - coins[i-1] >= 0)
        dp[i][j] += dp[i][j-coins[i-1]];
      }
      return dp[n][amount];
    }//28ms
    int change3(int amount, vector<int>& coins) 
    {      
      
      vector<int>dp(amount+1,0);
      dp[0]=1;
      for(auto coin : coins)
      for(int j = coin; j <= amount; j++)
      {                
        dp[j]+=dp[j-coin];        
      }
      return dp[amount];
    }//8ms    
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> coins = {1,5,10,25};
  cout<<sol.change(6,coins)<<endl;
  cout<<sol.change(35837,coins)%1000000007;
  return 0;
}