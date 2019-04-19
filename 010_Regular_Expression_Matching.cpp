#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 
class Solution 
{
public:
  bool isMatch(string s, string p) 
  {
    if( p.size() == 0)
      return s.size()==0;
    bool first_match = s.size()>0 && (s[0] == p[0] || p[0] == '.');
    if(p.size() >= 2 && p[1] == '*')
    {
      return isMatch(s,p.substr(2)) || ( first_match && isMatch(s.substr(1), p));
    }else
    {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
    
  }
  
  typedef pair<int,int> dp_key_type;
  map<dp_key_type,bool> dp;
  string str;
  string pattern;
  bool isMatchDP(string s, string p)
  {
    str = s;
    pattern = p;
    dp.clear();
    return isMatchDPHelp(0,0); 
  }
  bool isMatchDPHelp(int i , int j)
  {
    dp_key_type key{i,j};
    auto res = dp.find(key);
    if(res!= dp.end())
    {
      return res->second;
    }      
    else
    {
      int ssize=str.size()-i, psize=pattern.size()-j;
      bool res;
      if( psize == 0)
      {
        res= ssize==0;
        dp[key]=res;
        return res;
      }
      bool first_match = ssize >0 && (str[i] == pattern[j] || pattern[j] =='.');
      if(psize >= 2 && pattern[j+1] == '*')
      {
        res=isMatchDPHelp(i,j+2) || ( first_match && isMatchDPHelp(i+1,j));
        
      }else
      {
        res=first_match && isMatchDPHelp(i+1, j+1);
      }
      dp[key]=res;
      return res;
    }    
  }


};
int main(int argc, char const *argv[])
{
  Solution sol;
  
  string str,pattern;
  str="aaaaaa";
  pattern="a*";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  cout<<sol.isMatchDP(str,pattern)<<endl<<endl;
  pattern="a*.";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  cout<<sol.isMatchDP(str,pattern)<<endl<<endl;
  pattern=".*";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  cout<<sol.isMatchDP(str,pattern)<<endl<<endl;
  str="ab";
  pattern=".*c";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  cout<<sol.isMatchDP(str,pattern)<<endl<<endl;
  return 0;
}