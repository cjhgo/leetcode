#include<string>
#include<cctype>
using namespace std;
class Solution 
{
public:
    int myAtoi(string str) 
    {
        size_t cur=0;
        size_t next=cur+1;
        while(cur < str.length() and str[cur] == ' ')
            cur++;
        if(cur == str.length()) return 0;
        if(str[cur] == '+' || str[cur] == '-')
        {
            
        }
        else if(isdigit(str[cur])])
        {

        }
        else
        return 0;
    }
};