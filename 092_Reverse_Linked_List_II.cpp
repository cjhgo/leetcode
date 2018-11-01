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
        ListNode *cur = head, *new_head = new ListNode(-1), *pre = new_head;
        new_head->next = head;
        int i = 1;
        while( i < m)
        {
            pre = cur;
            cur = cur->next;
            i++;
        }

        while( i < n)
        {
            ListNode* to_move = cur->next;
            cur->next = to_move->next;
            to_move->next = pre->next;
            pre->next = to_move;        
            i++;    
        }
        return new_head->next;
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