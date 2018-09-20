#include<string>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int reverse(int x) 
    {
        int  negative = 1;
        int64_t xx = x;
        if( xx < 0)
        {
            negative = -1;            
            xx = -1*xx;            
        }
        string x_s = to_string(xx);        
        std::reverse(x_s.begin(), x_s.end());    
        string int_max = to_string(INT32_MAX);
        if(x_s.length() == int_max.length() and x_s > int_max)
        return 0;        
        return negative * stoi(x_s);;
    }
};
int main(int argc, char const *argv[])
{    
    Solution s;
    cout<<"range " << INT32_MIN << "\t"<< INT32_MAX<<endl;
    cout<<s.reverse(-2147483648)<<endl;
    cout<<s.reverse(123)<<endl;
    cout<<s.reverse(1534236469)<<endl;
    return 0;
}
