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
    int coinChange(vector<int>& coins, int amount)
    {
      int n = coins.size();
      int dp[n+1][amount+1];      
      
      for(int i = 0; i <=n; i++)
      dp[i][0] = 0;
      for(int i = 0; i <= amount; i++)
      dp[0][i] = -1;
      dp[0][0]=0;

      for(int i = 1; i <= n; i++)
      for(int j = 1; j <= amount; j++)
      {
        int temp = INT32_MAX;
        for(int k = 0; k <=  j/coins[i-1];k++)
        {
          int temp2 = dp [i-1][j - k*coins[i-1] ];
          if(temp2 >= 0 && temp2+k < temp)
          {            
            temp=temp2+k;
          }                  
        }
        if(temp == INT32_MAX) dp[i][j]=-1;
        else dp[i][j] = temp;
      }
      printMatrix<int>((int*)dp, n+1, amount+1);
      return dp[n][amount];
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> coins = {1,2,5};
  cout<<sol.coinChange(coins,11);
  return 0;
}