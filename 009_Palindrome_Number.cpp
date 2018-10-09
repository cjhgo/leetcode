#include<iostream>
using namespace std;
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if( x < 0)return false;
        int sum = 0, temp = x;
        while(temp != 0)
        {
            sum = (sum*10+temp%10);
            temp=temp/10;
        }
        return sum==x;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.isPalindrome(9889)<<endl;
    return 0;
}
