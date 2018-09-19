#include<climits>
#include<map>
#include<string>
#include<iostream>
using namespace std;
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        map<char,int> t_map;
        for(char c: t)
        t_map[c]++;
        int counter = t_map.size();
        int begin = 0, end = 0, len = INT_MAX;
        string res;
        while(end < s.length())
        {
            char end_char = s[end];
            if(t_map.count(end_char) == 1)
            {
                t_map[end_char]--;
                if(t_map[end_char] == 0)
                counter--;
            }
            end++;            
            while(counter == 0)
            {
                cout<<"\t"<<s.substr(begin, end)<<endl;
                if(end-begin < len)
                {
                    res = s.substr(begin, end-begin);
                    len = end -begin;
                }
                char begin_char = s[begin];
                if(t_map.count(begin_char) == 1)
                {
                    t_map[begin_char]++;
                    if(t_map[begin_char] > 0)
                    counter++;
                }
                begin++;
            }
        }
        return res;

    }
};
int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC", t = "ABC";
    //string s = "bac", t = "a";
    Solution solu;
    cout<<solu.minWindow(s,t);   
    return 0;
}