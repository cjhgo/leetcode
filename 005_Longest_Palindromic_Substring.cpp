#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution 
{
public:
    bool is_Palindrome(string s)
    {
        string copy(s);
        reverse(copy.begin(), copy.end());
        if( s == copy)
            return true;
        else
            return false;
    }
    string longestPalindrome(string s) 
    {
        size_t max_len = 0, begin = 0, end = 0;
        string res;
        for(size_t i = 0; i < s.length();i++)
        {
            for(size_t j = i+1; j <= s.length();j++)
            {
                string temp = s.substr(i, j-i);
                cout<<temp<<endl;
                if(is_Palindrome(temp) and j-i > max_len)
                {
                    max_len = j-i;
                    res = temp;
                }
            }
            cout<<endl;            
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    //string s("babad");    
    string s("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode");
    Solution sol;
    cout<<sol.longestPalindrome(s);
    return 0;
}