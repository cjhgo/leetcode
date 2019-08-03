#include <iostream>

class Solution
{
public:
  int lcs_iteraion(char const * A, char const * B, int m, int n)
  {
    int lcs [m][n];
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
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        std::cout<<lcs[i][j]<<"\t";
      }
      std::cout<<std::endl;
    }

    return lcs[m-1][n-1];       
  }
  int lcs_iteraion2(char const * A, char const * B, int m, int n)
  {
    int lcs[m+1][n+1];
    for(int i = 0; i <= m; i++)
    lcs[i][0]=0;
    for(int i = 0; i <= n; i++)
    lcs[0][i]=0;
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
      if(A[i-1] == B[j-1]) lcs[i][j] = 1+ lcs[i-1][j-1];
      else
      {
        lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
      }
      
    }
    for(int i = 0; i <= m; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        std::cout<<lcs[i][j]<<"\t";
      }
      std::cout<<std::endl;
    }

    return lcs[m][n];     
  }  

  int lcs_recursion(char const * A, char const * B, int m, int n)
  {

    // for(int i = 0; i < m; i++)
    // for(int j = 0; j < n; j++)
    // std::cout<<i<<"\t"<<j<<"\t"<<helper(A,B,i,j)<<std::endl;    
    return helper(A,B, m-1, n-1);
  }
  int helper(char const * A, char const * B, int lasta, int lastb)
  {
    std::cout<<lasta<<"\t"<<lastb<<std::endl;
    if(lasta==0 || lastb==0)
    {      
      for(int i = 0; i <= lastb;i++)
      if(B[i]==A[0]) return 1;

      for(int i = 0; i <= lasta;i++)
      if(A[i]==B[0]) return 1;
      return 0;
    }

    if(A[lasta] == B[lastb])
    {
      return 1+helper(A,B, lasta-1,lastb-1);
    }
    else
    {
      int res1 = helper(A,B,lasta,lastb-1);
      int res2 = helper(A,B,lasta-1,lastb);
      return std::max(res1, res2);
    }
  }
};

int main(int argc, char const *argv[])
{
  
  char const*  x = "GXTXAYB";
  char const*  y = "ACGTAB";
  Solution s;
  std::cout<<s.lcs_iteraion2(x,y, 7,6);
  return 0;
}
