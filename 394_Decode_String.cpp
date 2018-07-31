#include<iostream>
#include<string>
using namespace std;
class Solution 
{
public:
    inline string multiString(string s, int count)
    {
        string temp;
        for(int i = 0; i < count;i++)
        {
            temp += s;
        }
        return temp;
    }
    string genString(string s)
    {
        auto res = s.find("[");
        int count = stoi(s.substr(0,res));
        string base = s.substr(res+1, (s.size()-(res+1)-1) );
        return multiString(base, count);
    }
    string decodeString(string s) {
        return "";
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "2[abc]";
    cout<<s.decodeString(str)<<endl;
    cout<<s.genString(str)<<endl;
    cout<<s.multiString("abc",20);
    return 0;
}
