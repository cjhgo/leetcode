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
  bool isMatch(string s, string p) 
  {
    // cout<<s<<"\t"<<p<<endl;
    // if(p.size() == 0 )
    // {
    //     if(s.size()==0)return true;
    //     else return false;
    // }
    // if(p.size()>=2&&p[1]=='*')
    // {
    //   bool as_zero = isMatch(s,p.substr(2));      
    //   return as_zero || ((s[0]==p[0] || p[0] == '.') && isMatch(s.substr(1),p));
    // }else
    // {
    //   bool first_match = s[0]== p[0] || p[0] == '.';
    //   return first_match && isMatch(s.substr(1),p.substr(1));
    // }    
    if( p.size() == 0)
      return s.size()==0;
    bool first_mathc = s.size()>0 && (s[0] == p[0] || p[0] == '.');
    if(p.size() >= 2 && p[1] == '*')
    {
      return isMatch(s,p.substr(2)) || ( first_mathc && isMatch(s.substr(1), p));
    }else
    {
      return first_mathc && isMatch(s.substr(1), p.substr(1));
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
  pattern="a*.";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  pattern=".*";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  str="ab";
  pattern=".*c";
  cout<<sol.isMatch(str,pattern)<<endl<<endl;
  return 0;
}