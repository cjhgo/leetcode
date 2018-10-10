#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        size_t minlen = INT64_MAX;
        string minlen_str;
        for(auto str : strs)
        {
            if(str.length() < minlen)
            {
                minlen = str.length();
                minlen_str = str;
            }
        }
        while(minlen > 0)
        {
            int i = 0;
            for(auto str : strs)
            {
                if( str.substr(0, minlen) == minlen_str.substr(0, minlen) )
                {
                    i++;
                }
                else
                    break;
            }
            if( i == strs.size())
               break;
            minlen--;
        }
        return minlen_str.substr(0,minlen);
    }
};
int main(int argc, char const *argv[])
{
    vector<string> strs = {"flower","flow","flight"};
    Solution sol;
    cout<<sol.longestCommonPrefix(strs)<<endl;
    return 0;
}
