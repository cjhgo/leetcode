#include "struct_define.h"

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
    int getlen(ListNode* head)
    {
      
      int len = 0;
      for(;head!=nullptr; len++)
      {
        head=head->next;
      }
      
      return len;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
      int len1 = getlen(pHead1), len2 = getlen(pHead2);
      if( len1 == 0 || len2 == 0)
      {
        return nullptr;
      }
      if( len1 > len2 )
      {
        for(int i = 0; i+len2!=len1; i++)
        {
          pHead1 = pHead1->next;
        }
      }
      else
      {
        for(int i = 0; i+len1!=len2; i++)
        {
          pHead2 = pHead2->next;
        }
      }
      while(pHead1 && pHead2 && pHead1 != pHead2)
      {
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
      }
      if(pHead1)
      {
        std::cout<<pHead1->val<<std::endl;
      }
      return pHead1;
    }
};
int main(int argc, char const *argv[])
{
  ListNode a(1),b(2),c(3),d(4),e(5),f(6),g(7),h(8),i(9);

  a.next = &b;
  b.next = &c;
  c.next= &g;
  g.next = &h;
  h.next = &i;
  d.next = &e;
  e.next = &f;
  f.next = &g;
  
  Solution sol;
  printListNode(&a);
  printListNode(&e);
  ListNode* res;

  res =sol.FindFirstCommonNode(&a,&d);

  return 0;
}