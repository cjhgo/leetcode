#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if( nums.size() < 2 )
            return nums.size();
        int  diff = nums[1] - nums[0];
        int cnt, expect;
        if(diff == 0)
        {
            cnt = 1;
            expect = 0;
        }
        else
        {
            cnt = 2;
            expect = diff > 0 ? -1 : 1;
        }
        for(int i = 2; i < nums.size(); i++)
        {
            diff = nums[i] - nums[i-1];
            if(diff != 0)
            {
                int cur = diff > 0 ? 1 : -1;
                if(cur == expect or expect == 0)
                {
                    ++cnt;
                    expect = diff > 0 ? -1:1;                    
                }   
            }            
            //cout<<diff<<"#"<<nums[i]<<"#"<<cnt<<endl;
        }
        return cnt;
    }
};
int main(int argc, const char* argv)
{
    Solution s;
    //vector<int> n = {1,17,5,10,13,15,10,5,16,8};
    vector<int> n = {3,3,3,2,5};
    cout<<s.wiggleMaxLength(n);
}