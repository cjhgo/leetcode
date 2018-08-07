#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; i++)
        {
            bitset<sizeof(int)*8> x(i);
            res.push_back(x.count());
            cout<<x<<endl;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    for(auto e: s.countBits(855))
    {
        cout<<e<<endl;
    }
    return 0;
}
