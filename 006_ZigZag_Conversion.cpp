#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        ostringstream stream;
        size_t s_len = s.length();
        if( numRows == 1)
        return s;
        for(size_t i = 0; i < numRows; i++)
        {
            size_t pos = i;
            if(i == 0 or i == numRows-1)
            {                
                while( pos < s_len)
                {
                    stream<<s[pos];
                    pos += (2*numRows-2);
                }
            }
            else
            {
                while(pos < s_len)
                {
                    stream<<s[pos];
                    size_t pos2 = pos +(2*numRows-2*(i+1));
                    if( pos2 < s_len)
                    stream<<s[pos2];
                    pos += (2*numRows-2);
                }
            }
        }
        return stream.str();
    }
};
int main(int argc, char const *argv[])
{
    string s = "PAYPALISHIRING";
    Solution sol;
    cout<<sol.convert("A", 1);
    return 0;
}
