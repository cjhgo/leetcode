#include<algorithm>
#include<vector>
#include<set>
#include <bitset>
#include<map>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class Solution {
public:
    unsigned int char2val(char x)
    {
        switch (x)
        {
            case 'A' : return 0;
            case 'C' : return 1;
            case 'G' : return 2;
            case 'T' : return 3;
        }
    }
    unsigned int hashstr(string s)
    {
        if( s.size() != 10 )
        return 0;
        else
        {
            unsigned int number = 0;
            for(int i = 0; i < 10; i++)
            {
                number |= (  char2val(s[i])<< (18-2*i) );
            }
            return number;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> temp;
        vector<string> result;
        if(s.size() < 10 )
        return result;
        set<unsigned int> str_v;
        for(size_t i = 0; i <= s.size()-10;i++)
        {
            
            string sub_i = s.substr(i, 10);
            unsigned int key = hashstr(sub_i);
            if(str_v.count(key))
            {
                temp.insert(sub_i);
            }
            else
                str_v.insert(key);
        }        
        return vector<string>(temp.begin(),temp.end());
    }
};



int main(int argc, char const *argv[])
{
    Solution s;
    string str="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";    
    vector<string> res = s.findRepeatedDnaSequences(str);
    //string ww="ACGTTGCATT";    
    // unsigned int x = s.hashstr(ww);
    // cout<<bitset<20>(x)<<endl;
    // cout<<s.restore_str(x)<<endl;
    for(auto e : res)
        cout<<e<<endl;
    return 0;
}
/*
000000000000
00 11 01 11 11 00 10 01 11 10
00 11 01 11 11 00 10 01 11 10 
0 3 1 3 3 0 2 1 3 2
000000000000
00000000000000000001
0100000000000000000
*/