#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution 
{
public:
    map<char , vector<string> > num_2_chars = {
        {'2', { "a", "b", "c"}},
        {'3', { "d", "e", "f"}},
        {'4', { "g", "h", "i"}},
        {'5', { "j", "k", "l"}},
        {'6', { "m", "n", "o"}},
        {'7', { "p", "q", "r","s"}},
        {'8', { "t", "u", "v"}},
        {'9', { "w", "x", "y", "z"}}
    };
    vector<string> combinatons(string digits)
    {
        if(digits.size() == 2)
        {
            vector<string> temp;
            for(auto c : num_2_chars[ digits[0] ])
            {            
                for(auto d : num_2_chars[ digits[1] ])
                {
                    string s;
                    s += c;
                    s += d;
                    temp.push_back(s);
                }
            }
            return temp;
        }
        else
        {
            string sub = digits.substr(1, digits.size()-1);
            auto res = combinatons(sub);
            vector<string> temp;
            for(auto c : num_2_chars[ digits[0] ])
            {
                for(string _ : res)
                {
                    string s;                    
                    s += c;
                    s += _;
                    temp.push_back(s);
                }
            }
            return temp;
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)
        {
            return {};
        }
        else if(digits.size() == 1)
        {
            return num_2_chars[ digits[0] ];
        }
        else
        {
            return combinatons(digits);
        }
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string digits("2349");
    auto res = sol.letterCombinations(digits);
    cout<<res.size()<<endl;
    return 0;
}
