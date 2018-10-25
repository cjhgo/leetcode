#include<iostream>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head, *cur;
        head = new ListNode(-1);
        cur = head;
        for(;l1 != NULL; cur = cur->next)    
        {
            if( l2 == NULL)
            {
                cur->next = l1;
                return head->next;
            }
            if( l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;                
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
        }
        cur->next = l2;
        return head->next;
    }
};
int main(int argc, char const *argv[])
{
    ListNode a(1), b(3), c(5), d(6), e(7);
    ListNode f(2), g(4), h(8), i(10), j(11);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = &j;
    Solution sol;
    ListNode* res = sol.mergeTwoLists(&a, &f);
    while( res != NULL)
    {
        cout<<res->val<<"\t";
        res =res->next;
    }
    return 0;
}
