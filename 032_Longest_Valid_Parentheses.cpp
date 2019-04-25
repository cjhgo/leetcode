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
      int count=0;
      bool panic=false;
      stack<char> match;
      for(size_t i = 0; i < s.size();i++)
      {
        if(panic)
        {
          if(count > longest) longest=count;
          count=0;
        }
        match.push(i);
        while(not match.empty())
        {
          char next = s[++i];
          if(match.top() == ')')
          {
            panic=true;
            break;
          }
        }

      }
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  string s = "";
  cout<<sol.longestValidParentheses(s);
  string s = "(";
  cout<<sol.longestValidParentheses(s);
  string s = "())(()())";
  cout<<sol.longestValidParentheses(s);
  return 0;
}