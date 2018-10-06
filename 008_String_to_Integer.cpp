#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
class Solution 
{
public:
    int myAtoi(string str) 
    {
        size_t cur=0;
        size_t next=cur+1;
        char flag='+';
        ostringstream out;
        size_t slen = str.length();
        while(cur < slen and str[cur] == ' ')
            cur++;
        if( cur == slen ) return 0;
        if(str[cur] == '+' || str[cur] == '-')
        {
            flag = str[cur];
            ++cur;
            while(str[cur] == '0' and cur < slen)
            ++cur;
            if( cur == slen ) return 0;
            while( isdigit(str[cur]) and cur < slen)
            {
                out<<str[cur++];
            }
            cout<<out.str()<<endl;
        }
        else if(isdigit(str[cur]))
        {
            while(str[cur] == '0' and cur < slen)
            ++cur;
            if( cur == slen ) return 0;
            while( isdigit(str[cur]) and cur < slen)
            {
                out<<str[cur++];
            }
            cout<<out.str()<<endl;
        }
        else return 0;
        int64_t sum = 0;
        string temp = out.str();
        size_t tlen = temp.length();
        for(int i = tlen-1; i >= 0; i--)
        {
            int64_t y = (temp[i]-48)*pow(10, tlen-1-i);
            sum += y;//(temp[i]-48)*pow(10, tlen-1-i);
        }
        if(flag == '-')
        {
            if( tlen > 10 || sum >2147483648)
            return -2147483648;
            else if( sum <= 2147483648)
            return -1*sum;            
        }
        else if( flag == '+')
        {
            if( tlen > 10 || sum > 2147483647)
            return 2147483647;
            else if( sum <= 2147483647)
            return sum;            
        }
    }
};
int main(int argc, char const *argv[])
{
    //-2147483648
    //2147483647
    Solution sol;
    string str="    0000000000000   ";
    // cout<<INT32_MIN<<endl<<INT32_MAX<<endl;
    cout<<sol.myAtoi(str);
    return 0;
}
