#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int reverse(int x) 
    {
        int  negative = 1;
        if( x < 0)
        {
            negative = -1;
            x = -x;
        }
        string x_s = to_string(x);
        cout<<x_s<<endl;
        std::reverse(x_s.begin(), x_s.end());
        cout<<x_s<<endl;
        int res = stoll(x_s);
        return negative * res;
    }
};
int main(int argc, char const *argv[])
{
    int x = 1534236469;    
    Solution s;
    cout<<s.reverse(x);
    return 0;
}
