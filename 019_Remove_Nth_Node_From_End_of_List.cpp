#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * 
 **/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *pre, *cur,  *sentienl;    
        //pre=cur=next=sentienl=head;             
        cur = head;
        sentienl = cur;
        int count = 0;
        while( count < n)
        {
            count++;
            sentienl = sentienl->next;            
        }
        if( sentienl == NULL)
        {
            ListNode* ret = head->next;
            // free(head);
            return head->next;
        }
        else
        {
            pre = head;
            cur = head->next;
            sentienl = sentienl->next;
            while(sentienl != NULL )
            {
                pre = pre->next;
                cur = cur->next;    
                sentienl = sentienl->next;
            }
            pre->next = cur->next;
            return head;
        }            
    }
};
int main(int argc, char const *argv[])
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution sol;
    //ListNode* res = sol.removeNthFromEnd(&a, 3);
    ListNode* res = sol.removeNthFromEnd(&a, 5);
    while( res != NULL)
    {
        cout<<res->val<<"\t";
        res =res->next;
    }
    return 0;
}
