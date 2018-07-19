#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> str_cnt;
        cout<<s.size()<<endl;
        for(size_t i = 0; i <= s.size()-10;i++)
        {
            cout<<i;
            string sub_i = s.substr(i, 10);
            string::size_type pos = 0;
            while(true)
            {
                pos = s.find(sub_i,pos);
                cout<<pos<<endl;
                if(pos == string::npos)
                    break;
                else
                    ++pos;
            }            
        }
            
        vector<string> temp;
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
