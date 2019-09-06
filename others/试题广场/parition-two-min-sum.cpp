#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 

class Solution
{
 public:
  vector<int> input={1,4,5,8,9};

  void knapsack()
  {
    int m = input.size()+1, n = std::accumulate(input.begin(),input.end(),0)/2+1;
    int matrix[m][n];
    string choice[m][n];
    for(int i = 0; i < n; i++)
    {
      choice[0][i]="notuse";
      matrix[0][i]=0;
    }
    
    for(int i = 0; i < m; i++)
    {
      choice[i][0]="notuse";
      matrix[i][0]=0;
    }
    matrix[0][0]=0;

    for(int i = 1; i < m; i++)
    for(int j = 1; j < n; j++)
    {
      /**
       * dp[i][j]=max{dp[i-1][j],dp[i-1][j-c_i]+w_i}
       */
      int c_i = input[i-1];
      int dp_useci = j - c_i >= 0 ? matrix[i-1][j-c_i]+c_i:0;
      int dp_notuseci = matrix[i-1][j];
      matrix[i][j]=std::max(dp_notuseci, dp_useci);
      choice[i][j] = matrix[i][j] == dp_useci ? "useci":"notuse";
    }
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cout<<matrix[i][j]<<": "<<choice[i][j]<<"\t";
      }
      cout<<endl;
    }
    vector<bool> usei;
    int i=m-1, j =n-1;
    while (i > 0)
    {
      if(choice[i][j] == "useci")
      {
        j = j-input[i-1];
        usei.insert(usei.begin(),1);        
      }else
      {
        usei.insert(usei.begin(),0);        
      }
      i--;
    }
    for(auto e:usei)
    {
      cout<<e<<"\t";
    }
  }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  sol.knapsack();
  return 0;
}