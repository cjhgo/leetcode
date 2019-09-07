#include "struct_define.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 
class Solution 
{
public:
    vector<int> printListFromTailToHead(ListNode* head) 
    {
      if(head == nullptr)
      {
        return {};
      }
      stack<int> mys;
      vector<int> res;
      while (head !=  nullptr)
      {
        mys.push(head->val);
        head = head->next;
      }
      while (!mys.empty())
      {
        res.push_back(mys.top());
        mys.pop();
      }
      
      return res;
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  return 0;
}