#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int> p_map;
        for(char c : p)
            p_map[c]++;
        vector<int> res;
        size_t p_len = p.length(), s_len = s.length();
        size_t begin = 0, end = 0;
        string sub;
        if( s_len < p_len  || p_len == 0)
        return res;
        int counter = p_map.size();
        while( end < s_len)
        {
            char end_char = s[end];
            if(p_map.count(end_char) == 1)
            {
                p_map[end_char]--;
                if(p_map[end_char] == 0) 
                counter--;
            }
            end++;
            while(counter == 0)
            {
                if(end - begin == p_len)
                {
                    res.push_back(begin);
                }
                char begin_char = s[begin];
                if(p_map.count(begin_char) ==  1)
                {
                    p_map[begin_char]++;
                    if(p_map[begin_char] > 0)
                    counter++;
                }
                begin++;
            }
        }
        return res;
        //code like this will exceed time limit!
        // for(size_t i = 0; i <= s_len-p_len; i++)
        // {
        //     string temp = s.substr(i, p_len);
        //     sub = s.substr(begin, end);
            
        //     int counter = 0;
        //     auto temp2 = p_map;
        //     for(char c : temp)
        //     {
        //         temp2[c]--;
        //         if(temp2[c] == 0)                
        //             counter++;
        //     }
        //     if(counter == p_map.size())
        //     {
        //         res.push_back(i);
        //         cout<<temp<<endl;
        //     }
            
        // }        
    }
};
int main(int argc, char const *argv[])
{
    //string s = "cbaebabacd",  p = "abc";
    string s = "baa",  p = "aa";
    // string s = "",  p = "aa";
    Solution sol;

    for(auto e : sol.findAnagrams(s, p))
    cout<<e<<endl;
    return 0;
}
