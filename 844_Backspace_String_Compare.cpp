#include<iostream>
#include<string>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution 
{
public:
    string getreal(string s)
    {
        stack<char> mystack;
        for(auto c : s)
        {
            if( c == '#')
            {
                if(not mystack.empty())
                    mystack.pop();
            }
                
            else
                mystack.push(c);
        }
        string ss;
        while( not mystack.empty())
        {
            ss += mystack.top();
            mystack.pop();
        }
        return ss;
    }
    bool backspaceCompare(string S, string T) 
    {
        string a = getreal(S);
        string b = getreal(T);
        return a == b;
    }
};
int main() 
{
    string S = "ab#c", T="ad#c";
    bool ret = Solution().backspaceCompare(S, T);
    cout<<ret<<endl;
    return 0;
}
