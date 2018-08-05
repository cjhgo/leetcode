#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        map<int, int > ele_cnt;
        set<pair<int,int> > cnt_ele;
        for(int i = 0; i < nums.size(); i++)
        {
            ele_cnt[nums[i]]++;
        }
        for(auto e: ele_cnt)
        {
            cnt_ele.insert(pair<int,int>(e.second, e.first));
        }
        int j=0;
        int l=1;
        for(auto iter = cnt_ele.rbegin(); iter != cnt_ele.rend(); iter++)
        {
            res.push_back(iter->second);
            ++j;
            ++l;
            if(l > k)
            break;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={1,1,1,2,2,3};//,0,4,7,2};
    Solution s;
    for(auto e: s.topKFrequent(nums, 2))
    cout<<e<<endl;
    return 0;
}