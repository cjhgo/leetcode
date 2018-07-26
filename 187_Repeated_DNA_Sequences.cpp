#include<vector>
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
    char val2char(unsigned int x)
    {
        switch (x)
        {
            case 0  : return 'A' ;
            case 1  : return 'C' ;
            case 2  : return 'G' ;
            case 3  : return 'T' ;
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
                unsigned int temp = char2val(s[i]);
                unsigned int temp2 = (temp << (18-2*i));
                // cout<<bitset<20>(number)<<endl
                //     <<bitset<20>(temp)<<endl
                //     <<bitset<20>(temp2)<<endl;
                number |= temp2;
                //cout<<bitset<20>(number)<<endl<<endl;
            }
            return number;
        }
    }
    string restore_str(unsigned int number)
    {        
        stringstream ss;
        for(size_t i = 0; i < 10; i++)
        {
            unsigned int temp = number >> (18-2*i);
            unsigned int temp2 = temp & 3UL;
            char x = val2char(temp2);
            //ss<<val2char(temp2);
            // cout<<bitset<20>(number)<<endl
            //     <<bitset<20>(temp)<<endl
            //     <<bitset<20>(temp2)<<endl
            //     <<x<<endl;
            ss<<x;
        }
        return ss.str();
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> temp;
        if(s.size() < 10 )
        return temp;
        map<unsigned int,int> str_cnt;
        for(size_t i = 0; i <= s.size()-10;i++)
        {
            
            string sub_i = s.substr(i, 10);
            unsigned int key = hashstr(sub_i);
            str_cnt[key]++;
        }        
        for(auto e : str_cnt)
        {            
            cout<<e.first<<"#"<<e.second<<endl;
            if(e.second > 1)
            {
                string t = restore_str(e.first);
                temp.push_back(t);
            }
        }        
        return temp;
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