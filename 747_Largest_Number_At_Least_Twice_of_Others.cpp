#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    auto max_pos = max_element(nums.begin(), nums.end());
    size_t index = std::distance(nums.begin(), max_pos);
    int max_e = *max_pos;
    for(size_t i = 0; i < nums.size(); i++)
    {
        if( nums[i]* 2 > max_e)
        {
            if( i != index)
                return -1;
        }        
    }
    return index;
}
};

int main(int argc, char const *argv[])
{

    Solution s;
    vector<int> a = {0,0,0,1};
    cout<<s.dominantIndex(a);
}