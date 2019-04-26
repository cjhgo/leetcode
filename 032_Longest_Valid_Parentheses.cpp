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
      typedef pair<char,size_t> ele_type;
      stack<ele_type> match;
      size_t i = 0;
      match.push({s[i],i});
      while(not  match.empty() || (i+1) < s.size())
      {        
        if( i+1 ==s.size())break;
        ele_type next{s[i+1],i+1};
        if( not match.empty() && match.top().first == '(' && next.first==')')
        {
          match.pop();
        }else
        {
          match.push(next);
        }          
        i++;                
      }
      if (match.empty())return s.size();
      else
      {        
        vector<size_t> not_match;        
        while(not match.empty())
        {        
          not_match.push_back(match.top().second);
          match.pop();
        }  
        int temp =s.size()-1 - not_match[0];        
        if(  temp > longest) longest=temp;
        temp = not_match[not_match.size()-1]-0;
        if(  temp > longest) longest=temp;
        for(int i = 0;i+1 <= not_match.size()-1;i++)
        {
          temp = not_match[i]-not_match[i+1]-1;
          if(  temp > longest) longest=temp;
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