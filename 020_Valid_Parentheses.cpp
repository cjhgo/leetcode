#include<iostream>
#include<stack>
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
    bool isValid(string s) 
    {
        stack<char> mystack;

        map<char,char> expect = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        while(not s.empty())
        {
            char a = s[0];
            if(a == '(' || a == '{' || a == '['  )            
                mystack.push(a);
            else
            {
                if( mystack.empty() )
                    return false;
                else
                {
                    char top = mystack.top();
                    char expect_char = expect[top];
                    if( a == expect_char)
                        mystack.pop();
                    else
                        return false;
                }
            }                        
            s = s.substr(1);
        }
        if( mystack.empty() )
            return true;
        else
            return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    string s("{[]}");
    cout<<sol.isValid(s);
    return 0;
}