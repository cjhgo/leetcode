#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(), citations.end());
        for(int i = citations.size(); i >= 0 ; i--)
        {
            auto pos = std::lower_bound(citations.begin(), citations.end(), i);
            if(pos != citations.end())
            {
                size_t len = std::distance(pos, citations.end());
                if(len >= i)
                    return i;
            }          
        }
        return 0;
    }
};
int main(int argc, char* argv)
{
    vector<int> citations={3,0,6,1,5};
    Solution s;
    cout<<s.hIndex(citations);

}