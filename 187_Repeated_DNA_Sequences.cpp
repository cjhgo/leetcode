#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> temp;
        if(s.size() < 10 )
        return temp;
        map<string,int> str_cnt;
        cout<<s.size()<<endl;
        for(size_t i = 0; i <= s.size()-10;i++)
        {
            
            string sub_i = s.substr(i, 10);
            cout<<"to find,from "<<i<<sub_i<<endl;
            string::size_type pos = 0;
            while(true)
            {
                pos = s.find(sub_i,pos);            
                if(pos == string::npos)
                    break;
                else
                {
                    cout<<pos<<s.substr(pos, 10)<<endl;
                    ++pos;
                    str_cnt[sub_i]++;
                }
                    
            }            
        }
        
        for(auto e : str_cnt)
        {            
            cout<<e.first<<e.second<<endl;
            if(e.second > 1)
                temp.push_back(e.first);
        }
        
        return temp;
    }
};



int main(int argc, char const *argv[])
{
    Solution s;
    string str="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";    
    vector<string> x = s.findRepeatedDnaSequences(str);
    // for(auto e: x)
    //     cout<<e<<endl;
    return 0;
}
