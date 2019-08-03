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
    int minD_baselcs(string word1, string word2)
    {
      int m = word1.size(), n = word2.size();
      int lcs[m+1][n+1];
      for(int i = 0; i <= m; i++)
      lcs[i][0]=0;
      for(int i = 0; i <= n; i++)
      lcs[0][i]=0;
      for(int i = 1; i <= m; i++)
      for(int j = 1; j <= n; j++)
      {
        
        if(word1[i-1] == word2[j-1])
        lcs[i][j] = 1+lcs[i-1][j-1];
        else
        lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
      }

      int temp = lcs[m][n];
      return m-temp+n-temp;
    }
    int minDistance(string word1, string word2) 
    {
      return minD_baselcs(word1, word2);
    }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  cout<<sol.minDistance("sea", "eat");
  return 0;
}