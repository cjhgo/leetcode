#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> lr,rl;
        for(auto e : s)
        {
            if(isalnum(e))
            {
                lr.push_back(toupper(e));
            }
        }
        for(int j = s.size()-1; j >= 0;j--)
        {
            if(isalnum(s[j]))
            {
                rl.push_back(toupper(s[j]));
            }
        }
        for(size_t i = 0; i < lr.size();i++)
        {
            //cout<<lr[i]<<"\t"<<rl[i]<<endl;
            if(lr[i] != rl[i])
                return false;
        }
        return true;       
    }
};

int main(int argc, const char* argv[])
{
    Solution s;
    cout<<s.isPalindrome("0P");
}