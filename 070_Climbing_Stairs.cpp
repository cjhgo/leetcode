#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution 
{
public:
    int climbStairs(int n) 
    {
        vector<int> v = {0,1,2};
        v.resize(n+1);
        if( n >= 3)
        {
            for(size_t j = 3; j<= n;j++)
            {
                v[j] = v[j-2]+v[j-1];
            }
        }
        return v[n];
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.climbStairs(6);
    return 0;
}