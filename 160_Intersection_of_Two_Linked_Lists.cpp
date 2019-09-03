


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
    ListNode* getIntersectionNode( ListNode* pHead1, ListNode* pHead2) 
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
      }      while(pHead1 && pHead2 && pHead1 != pHead2)
      {
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
      }
      return pHead1;
    }
};