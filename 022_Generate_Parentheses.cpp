#include<iostream>
#include<algorithm>
#include<bitset>
#include<stack>
#include<cmath>
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
            {'1', '0'},
        };
        while(not s.empty())
        {
            char a = s[0];
            if(a == '1' )            
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
    vector<string> generateParenthesis(int n) 
    {
        if( n == 1) return {"()"};
        int k = 2*(n -1);
        vector<string> res;
        for(int i = 0; i < (pow(2,k)-1);i++ )
        {
            bitset<64> num(i);            
            size_t num_1 = num.count();
            size_t num_0 = k-num_1;
            if(num_0 == num_1)
            {
                string num_str = num.to_string().substr(64-k);
                num_str = "1"+num_str+"0";                                
                if(isValid(num_str))
                {                    
                    replace(num_str.begin(), num_str.end(), '1', '(');
                    replace(num_str.begin(), num_str.end(), '0', ')');
                    cout<<i<<"\t"<<num_str<<"\t"<<num_0<<"\t"<<num_1<<endl;
                    res.push_back(num_str);
                }
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    sol.generateParenthesis(1);
    return 0;
}