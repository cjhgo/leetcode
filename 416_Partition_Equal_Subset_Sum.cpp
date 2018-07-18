#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto e : nums)
            sum += e;
        if( sum % 2 != 0)
            return false;
        int temp = 0;
        int target = sum / 2;
        cout<<"sum,target"<<sum<<","<<target<<endl;
        for(auto e: nums)
        {   
            
            temp += e;
            cout<<e<<"#"<<temp<<endl;
            if( temp == target)
                return true;
        }      
//        auto res = find(nums.begin(), nums.end(), target);
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums={19,33,38,60,81,49,13,61,50,73,60,82,73,29,65,62,53,29,53,86,16,83,52,67,41,53,18,48,32,35,51,72,22,22,76,97,68,88,64,19,76,66,45,29,95,24,95,29,95,76,65,35,24,85,95,87,64,97,75,88,88,65,43,79,6,5,70,51,73,87,76,68,56,57,69,77,22,27,29,12,55,58,18,30,66,53,53,81,94,76,28,41,77,17,60,32,62,62,88,61};
    //{1, 5, 11, 5};
    //vector<int> nums={1,1};
    cout<<s.canPartition(nums);
    return 0;
}
