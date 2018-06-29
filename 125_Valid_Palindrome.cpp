#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for(auto e : s)
        {
            cout<<isalpha(e)<<"#"<<e<<endl;
        }
            
        return 1;       
    }
};

int main(int argc, const char* argv[])
{
    Solution s;
    cout<<s.isPalindrome("A man, a plan, a canal: Panama");
}