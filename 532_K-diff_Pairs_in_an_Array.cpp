#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdlib>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int n = 0;
        set< pair<int,int> > pairset;
        // sort( nums.begin(), nums.end() );
        // nums.erase( unique( nums.begin(), nums.end() ), nums.end() );        
        size_t len = nums.size();
        if(len > 0){
        for(size_t i = 0; i < len-1; i++)
        {
            for(size_t j = i+1; j < len; j++)
            {
                if(abs(nums[i]-nums[j]) == k)
                {
                    cout<<nums[i]<<"#"<<nums[j]<<endl;
                    int a = max(nums[i], nums[j]);
                    int b = min(nums[i], nums[j]);
                    pair<int,int> x(a, b);
                    pairset.insert(x);
                    
                    // ++n;
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
    //vector<int> nums={1,1,1,2,1};
    vector<int> nums={};
    cout<<s.findPairs(nums,0);
    return 0;
}
