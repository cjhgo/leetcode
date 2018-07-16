#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        set< pair<int,int> > pairset;
        sort( nums.begin(), nums.end() );
        size_t len = nums.size();
        if(len > 0)
        {
            for(size_t i = 0; i < len-1; i++)
            {
                for(size_t j = i+1; j < len; j++)
                {
                    if(abs(nums[i]-nums[j]) == k)
                    {
                        pair<int,int> x(nums[i], nums[j]);
                        pairset.insert(x);
                    }
                    
                }
            }
            return pairset.size();
        }
        else
            return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums={1,1,1,2,1};
    //vector<int> nums={};
    cout<<s.findPairs(nums,0);
    return 0;
}
