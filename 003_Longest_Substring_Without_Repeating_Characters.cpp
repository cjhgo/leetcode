#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_length =0;
        for(int i = 0; i < s.length();i++)
        {
            string sub_i(1,s[i]);
            for(int j = i+1; j < s.length();j++)
            {
                if(sub_i.find(s[j]) == string::npos)
                {
                    sub_i += s[j];
                }
            }
            if(sub_i.length() > max_length)
            max_length = sub_i.length();
            cout<<sub_i<<endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    
    string s = "pwwkew";
    Solution ss;
    cout<<ss.lengthOfLongestSubstring(s);
    return 0;
}