#include<string>
#include<cmath>
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
    string longestPalindrome_dp(string s) 
    {
        string res;
        size_t s_len = s.length();
        size_t max_len = 0;
        vector< vector<int> > flag(s_len, vector<int>(s_len, 0));
        for(size_t k = 1; k <= s_len;k++)
        {
            for(size_t i = 0; i+k <= s_len;i++ )
            {
                size_t j = i+k-1;
                if( k == 1)
                {
                    flag[i][j] = 1;
                    max_len = 1;
                    res = s.substr(i,k);
                }
                else if( k == 2)
                {
                    if( s[i] == s[j])
                    {
                        flag[i][j] = 1;
                        res = s.substr(i,k);
                    }
                    else
                    flag[i][j] = 0;
                }
                else
                {
                    if(flag[i+1][j-1] and s[i] == s[j] )
                    {
                        flag[i][j] = 1;
                        max_len = k;
                        res = s.substr(i,k);
                    }
                    else
                    {
                        flag[i][j] = 0;
                    }
                }
            }
        }
        return res;

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
    string longestPalindrome(string s) 
    {
        size_t s_len = s.length();
        string res;
        size_t max_len = 0;
        for(size_t i = 0; i < s_len;i++)
        {   size_t cur_len = 1;
            size_t left = i -1, right = i + 1;
            while( left < s_len && right < s_len)
            {
                if(s[left] == s[right])
                {
                    left--;
                    right++;
                    cur_len += 2;
                }
                else
                break;
            }
            if(cur_len > max_len)
            {
                max_len = cur_len;
                res = s.substr(i-cur_len/2, cur_len);
            }
        }
        for(double j = 0.5; j < s_len;j+=1)
        {
            size_t left = floor(j), right = ceil(j);
            size_t temp = left;
            size_t cur_len = 0;
            while( left < s_len && right < s_len)
            {
                if( s[left] == s[right])
                {
                    left--;
                    right++;
                    cur_len += 2;
                }
                else
                    break;
            }
            if( cur_len > max_len)
            {
                max_len = cur_len;
                res = s.substr(temp+1 - cur_len/2, cur_len);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    string s("abbd");    
    Solution sol;
    cout<<sol.longestPalindrome(s);
    return 0;
}