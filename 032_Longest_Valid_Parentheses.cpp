#include"struct_define.h"
#include<iostream>
#include<vector>
#include<stack>
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
    int longestValidParentheses(string s) 
    {
      if(s.size() < 2) return 0;
      int longest=0;

      stack<int> mystack;
      mystack.push(-1);
      for(size_t i = 0 ; i < s.size();i++)
      {
        if( s[i] =='(')
          mystack.push(i);
        else
        {
          mystack.pop();
          if(mystack.empty())
          {
            mystack.push(i);
          }
          else
          {
            int temp = i-mystack.top();
            if(temp > longest)
            longest=temp;
          }
        }
      }
      return longest;
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  string s = "";
  cout<<sol.longestValidParentheses(s)<<endl<<endl;
  s = "(";
  cout<<sol.longestValidParentheses(s)<<endl<<endl;
  s = "()";
  cout<<sol.longestValidParentheses(s)<<endl<<endl;  
  s = "())(()())";
  cout<<sol.longestValidParentheses(s)<<endl<<endl;  
  s=")()())";
  s="()(()";
  s=")()())";
  cout<<sol.longestValidParentheses(s)<<endl<<endl;
  return 0;
}