#include<iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * result = new ListNode(0);
        ListNode *cur = result;
        int carry=0;        
        while(l1 != nullptr or l2 != nullptr or carry != 0)        
        {            
            int v1,v2;
            v1=v2=0;
            if(l1 != nullptr)
            {
                v1=l1->val;
                l1=l1->next;                
            }
            if(l2 != nullptr)
            {
                v2=l2->val;
                l2=l2->next;                
            }
            int temp = v1+v2+carry;
            int value = temp % 10;            
            cur->val = value;
            carry = temp / 10;            
            if(l1 != nullptr or l2 != nullptr or carry != 0)
            {            
            cur->next =new ListNode(0);
            cur=cur->next;            
            }
        }    
        return result;
    }
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) 
    {
        ListNode * header = new ListNode(0);
        ListNode *cur = header;
        int carry=0;        
        while(l1 != nullptr or l2 != nullptr or carry != 0)        
        {            
            int v1,v2;
            v1=v2=0;
            if(l1 != nullptr)
            {
                v1=l1->val;
                l1=l1->next;                
            }
            if(l2 != nullptr)
            {
                v2=l2->val;
                l2=l2->next;                
            }
            int temp = v1+v2+carry;
            int value = temp % 10;                        
            carry = temp / 10;                                
            cur->next =new ListNode(value);
            cur=cur->next;            
        }    
        return header->next;
    }
};
int main(int argc, char const *argv[])
{
    ListNode a(5),b(4),c(3),h(8);
    ListNode d(5),e(6),f(4);
    // a.next = &b;
    // b.next=&c;
    // c.next=&h;

    // d.next=&e;
    // e.next=&f;
    Solution s;
    ListNode* res = s.addTwoNumbers2(&a,&d);
    cout<<res->val<<res->next->val;
    //cout<<res->val<<res->next->val<<res->next->next->val;
    //<<res->next->next->next->val<<endl;
    return 0;
}
