#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution 
{
public:  
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        this->nums = nums;
        this->L = this->nums.size();
        vector<int> t(this->L);
        helper(t,0);
        return this->res;
    }
    void helper(vector<int>& tmp,int cur)
    {
        if( cur == L)
        {
            this->res.push_back(tmp);
            return;
        }                
        auto tt = this->nums;
        for(int i = 0; i < cur; i++)
        {
            auto f = find(tt.begin(),tt.end(), tmp[i]);
            if( f != tt.end())
            {
                tt.erase(f);
            }
        }
        for(int i = 0; i < tt.size();i++)
        {                        
            if(i>=1 && tt[i] == tt[i-1])continue;
            auto e = tt[i];
            tmp[cur]=e;
            helper(tmp,cur+1);        
        }
    }
private:
    int L;
    vector<int> nums;
    vector<vector<int>> res;    
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,2};
    //{1,2,2,2,3,4,4,5,7};
    Solution s;
    for(auto e:s.permuteUnique(nums))
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    
    return 0;
}
