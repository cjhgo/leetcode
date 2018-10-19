#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution 
{
public:
    int helper(vector<int>& nums, size_t left, size_t right)
    {
        int count = 0;        
        size_t a = left, middle = (left+right)/2, c=middle+1;
        size_t d = middle+1 ,e = left;
        vector<int> temp;
        while( d <= right)
        {
            while( e <= middle )
            {
                if( (int64_t)nums[d]*2 < nums[e])
                {
                    count += (middle -e +1);
                    break;
                }
                else
                    e++;
            }
            d++;
        }
        // while(a <= middle || c <= right)
        // {
        //     if( a <= middle && c > right)
        //     {
        //         temp.push_back(nums[a]);
        //         a++;                
        //     }
        //     else if( a > middle && c <= right)
        //     {
        //         temp.push_back(nums[c]);
        //         c++;                
        //     }
        //     else if( a <= middle &&  c <= right)
        //     {
        //         if(nums[c] < nums[a])
        //         {   
        //             temp.push_back(nums[c]);
        //             c++;
        //         }
        //         else
        //         {
        //             temp.push_back(nums[a]);
        //             a++;
        //         }
        //     }
        // }
        merge(nums.begin()+left, nums.begin()+middle+1,
                nums.begin()+middle+1, nums.begin()+right+1,
                back_inserter(temp));                        
        copy(temp.begin(), temp.end(), nums.begin()+left);
        // use merge sort 
        // do not use sort algorihtm, 
        // cause left /right part is already sorted
        // sort(nums.begin()+left, nums.begin()+right+1);
        return count;
    }
    int reverse(vector<int>& nums, size_t left, size_t right)
    {        
        if(left == right)
        return 0;
        if(left+1 == right)
        {
            int count = 0;
            if(nums[left] > (int64_t)nums[right]*2)
            count = 1 ;
            if(nums[left] > nums[right])
            swap(nums[left], nums[right]);
            return count;

        }
        else
        {
            int middle = (left+right)/2;
            int leftv = reverse(nums, left, middle);
            int rightv = reverse(nums, middle+1, right);
            int both = helper(nums, left, right);
            return leftv+rightv+both;
        }

    }
    int reversePairs(vector<int>& nums) 
    {
        if(nums.size() < 2) return 0;
        return reverse(nums, 0, nums.size()-1);
    }
    int reversePairs2(vector<int>& nums) 
    {
        int count = 0;
        for(size_t i = 0; i < nums.size()-1; i++)
        {
            for(size_t j = i+1; j < nums.size(); j++)
            {                
                int64_t a = nums[i], b = (int64_t)nums[j] * 2;
                if(a > b) count++;
            }
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{    
    //vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};    
    vector<int> nums = {1,3,2,3,1};
    Solution sol;
    cout<<sol.reversePairs(nums)<<endl;
    for(auto e: nums)
    cout<<e<<"\t";
    return 0;
}
