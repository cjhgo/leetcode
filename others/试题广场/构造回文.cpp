#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/**
 * 题目链接: https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
 * 题目来源: 腾讯2017暑期实习生编程题,难度2星
 * 题目说明 
 * 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。
 * 如何删除才能使得回文串最长呢？输出需要删除的字符个数。
 * 最长回文串 等价于 lcs(string, reverse_string) 
 * 因此这道题可以通过 最长公共子序列(lcs) 这个原型题目来解决
 */

  int lcs_iteraion(string A, string B, int m, int n)
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
    return lcs[m-1][n-1];
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
