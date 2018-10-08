#include<iostream>
#include<climits>
#include<string>
#include<cctype>
using namespace std;
class Solution 
{
public:
    int myAtoi(string str) 
    {
        int plus = 1;
        size_t slen = str.length();
        size_t index = str.find_first_not_of(' ');
        int64_t sum = 0;
        while( index < slen)
        {
            if( str[index] == '+' || str[index] == '-')
            {
                plus = str[index] == '-' ? -1 : 1;
                ++index;            
            }
            //此处加了else,就无法处理 +-2 这样的test case
            while(isdigit(str[index]))
            {
                sum = sum*10+(str[index]-'0');
                index++;
                if(sum > INT_MAX)
                return (plus==1) ? INT_MAX: INT_MIN;
            }
            return sum*plus;    
        }
        return sum;
        
    }
};
int main(int argc, char const *argv[])
{
    //-2147483648
    //2147483647
    Solution sol;
    cout<<sol.myAtoi("    0000000000000   ")<<endl;
    cout<<sol.myAtoi("+-2")<<endl;
    cout<<sol.myAtoi("0-1")<<endl;
    cout<<sol.myAtoi("+2147483648")<<endl;
    cout<<sol.myAtoi("-2147483648")<<endl;
    cout<<sol.myAtoi("+2147483649")<<endl;
    cout<<sol.myAtoi("-2147483649")<<endl;
    return 0;
}
