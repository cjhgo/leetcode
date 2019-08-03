#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int lcs[1002][1002];
  int lcs_iteraion(string A, string B, int m, int n)
  {
    // int lcs [m][n];
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
    {
      if(i == 0 || j == 0)
      { 
        if( i== 0 && j == 0) lcs[0][0] = A[i] == B[j];
        if( A[i] == B[j]) lcs[i][j] = 1;
        else if(j > 0)
        {                    
          lcs[i][j] = lcs[i][j-1];          
        }
        else if(i > 0)
        {
          lcs[i][j] = lcs[i-1][j];
        }
      }
      else
      {
        if(A[i] == B[j]) lcs[i][j] = 1+ lcs[i-1][j-1];
        else
        {
          lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
        }
      }
    }

    return lcs[m-1][n-1];
    // std::cout<<i<<"\t"<<j<<"\t"<<helper(A,B,i,j)<<std::endl;        
  }
int main(int argc, char const *argv[])
{
  string input;
  while (cin>>input)
  {    
    string input2=input;
      
    std::reverse(input2.begin(),input2.end());  
    // cout<<lcs_iteraion(fromleft,fromright,input.size(),input.size());
    cout<<input.size()-lcs_iteraion(input,input2,input.size(),input.size())<<endl;
  }  
  return 0;
}
