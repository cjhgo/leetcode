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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* res = new ListNode(-1);
        while(head != NULL)
        {
            ListNode* origin_head = res->next;
            res->next = head;            
            head = head->next;
            res->next->next = origin_head;            
        }
        return res->next;
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
    ListNode* res = sol.reverseList(&a);
    while( res != NULL)
    {
        cout<<res->val<<"\t";
        res =res->next;
    }
    return 0;
}