#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution 
{
public:
    bool is_Palindrome(string s)
    {
        string copy;
        reverse_copy(s.begin(),s.end(), inserter(copy,copy.begin()));
        cout<<"\n...\n"<<s<<"...\n"<<copy<<endl;
        if( s == copy)
            return true;
        else
            return false;
    }
    string longestPalindrome(string s) 
    {
        size_t s_len = s.length();
        vector<int> temp(s_len, 0);
        size_t max_len = 0;
        vector< vector<int> > flag(s_len, vector<int>(s_len, 0));
        for(size_t i = 0; i < s_len;i++)
        {
            flag[i][i]=1;
            if( i+1 < s_len)
                flag[i][i+1]= (s[i] == s[i+1]);
        }        
        return "";

    }
    string longestPalindrome_brute_force(string s) 
    {
        size_t max_len = 0, begin = 0, end = 0;
        string res;
        for(size_t i = 0; i < s.length();i++)
        {
            for(size_t j = i+1; j <= s.length();j++)
            {
                string temp = s.substr(i, j-i);
                cout<<temp<<endl;
                if(is_Palindrome(temp) and j-i > max_len)
                {
                    max_len = j-i;
                    res = temp;
                }
            }
            cout<<endl;            
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    string s("babab");    
    Solution sol;
    cout<<sol.longestPalindrome(s);
    cout<<sol.is_Palindrome(s);
    return 0;
}