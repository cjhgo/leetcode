#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> permute2(vector<int>& nums) 
    {    
        size_t n = nums.size();
        size_t res = pow(n,n);        
        size_t target_sum=0;        
        vector<vector<int>> resv;
        for(int i = 0; i < n;i++)
        target_sum+= i;
        vector<int> permute_bit(n,0);
        int temp,temp2,j,remainder;
        for(int i =0; i < res; i++)
        {            
            temp=i;
            temp2=j=0;
            while(temp != 0)
            {
                remainder = temp % n;
                temp = temp / n;
                
                permute_bit[j++] = remainder;
                temp2 += remainder;
            }
            if(temp2 == target_sum)
            {
                bool add = true;
                for(size_t k = 0; k < n; k++)
                {
                    if(find(permute_bit.begin()+k+1,permute_bit.end(), permute_bit[k]) != permute_bit.end())
                    add=false;
                }
                if(add)resv.push_back(permute_bit);
            }
                
        }
        cout<<resv.size()<<endl;
        vector<int> tempv(n,0);
        for(size_t l = 0; l < resv.size();l++)
        {            
            for(int x = 0; x < n;x++)
            tempv[x] = nums[resv[l][x]];
            resv[l]=tempv;
        }        
        for(auto e:resv)
        {
            for(auto ee: e)
            cout<<ee<<"\t";        
            cout<<endl;
        }
        return resv;
    }
    vector<vector<int>> permute(vector<int>& nums)
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
    // s.permute(nums);
    for(auto e:s.permute(nums))
    {
        for(auto ee: e)
        cout<<ee<<"\t";
        cout<<endl;
    }
    
    return 0;
}
