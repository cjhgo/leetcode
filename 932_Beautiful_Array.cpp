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
    vector<int> helper(map<int, vector<int> >& memorized, int N)
    {
        auto it = memorized.find(N);
        if( it != memorized.end())    
        {
            cout<<"hit!!\n";
            return it->second;
        }
            
        else
        {
            vector<int> temp;
            int a = (N+1)/2, b = N/2;
            auto left = helper(memorized, a);

            for(auto e: left)
            {
                temp.push_back(2*e-1);
            }
            auto right = helper(memorized, b);

            for(auto e: right)
            {
                temp.push_back(2*e);
            }
            memorized[N]= temp;
            return temp;
        }
    }
    vector<int> beautifulArray(int N) 
    {

        map<int, vector<int> > memorized ={
            {1, {1}},
            {2, {1,2}},
            {3, {1,3,2}}
        };
        return helper(memorized, N);
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    for(auto e : sol.beautifulArray(30))
    {
        cout<<e<<"\t";
    }
    return 0;
}