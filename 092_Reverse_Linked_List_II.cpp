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
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        
        ListNode *cur = head, *pre;// = new ListNode(-1);// = cur;
        int i = 1;
        if ( m == 1)
        {
            pre = new ListNode(-1);
            pre->next = cur;
        }
        else
        {
            while( i < m)
            {
                pre = cur;
                cur = cur->next;
                i++;
            }
        }        
        ListNode* tail = cur;
        cur = cur->next;
        tail->next = NULL;
        i++;
        while( i <= n)
        {
            ListNode* ori = pre->next;
            pre->next = cur;
            cur  = cur->next;
            pre->next->next = ori;
            i++;
        }
        if( cur != NULL)tail->next = cur;
        if( m == 1) return pre->next;
        else return head;
    }
};
int main(int argc, char const *argv[])
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    // a.next = &b;
    // b.next = &c;
    // c.next = &d;
    // d.next = &e;
    c.next=&e;

    Solution sol;
    ListNode* res = sol.reverseBetween(&c, 1, 2);
    while( res != NULL)
    {
        cout<<res->val<<"\t";
        res =res->next;
    }
    return 0;
}