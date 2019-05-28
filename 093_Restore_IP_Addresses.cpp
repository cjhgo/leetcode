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
class Solution {
public:
    void helper(int cur)
    {
      if( cur == 4)
      {
        string t;
        int sum = 0;
        for(int i = 0; i < 4; i++)
        {
          auto tt = s.substr(sum, lens[i]);
          if(tt[0]=='0'&&tt.length() > 1) return;
          t += tt;
          sum += lens[i];
          if( i < 3) t+=".";
        }
        this->res.push_back(t);
        return;
      }
      for(int i = 1; i < 4; i++)
      {
        lens[cur] = i;
        int sum=0;        
        for(int i = 0; i < cur;i++)
        {
          sum += lens[i];
        } 
        if( cur == 3 )
        {
          if( i == (s.length()-sum))
          {
            if( stoi(s.substr(sum,i)) <= 255)
              helper(cur+1);
          }
        }else
        {
          if( sum < s.length() && stoi(s.substr(sum,i)) <= 255)
            helper(cur+1);
        }        
      }
    }
    vector<string> restoreIpAddresses(string s) 
    {
      this->s = s;
      this->lens.resize(4);
      helper(0);
      return res;
    }

private:
  vector<string> res;
  vector<int> lens;
  string s;    
};
int main(int argc, char const *argv[])
{
  Solution sol;
  auto fuck = sol.restoreIpAddresses("25525511135");
  fuck = sol.restoreIpAddresses("010010");
  for(auto e: fuck)
  {
    cout<<e<<endl;
  }
  return 0;
}