#include<iostream>
#include<algorithm>
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

    int findKthLargest1(vector<int>& nums, int k) 
    {
        //逆序增序,即顺序降序
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
    int findKthLargest2(vector<int>& nums, int k) 
    {
        //第k大的元素就是升序中第 size-k个元素,
        //比如5个元素中第2大的就是升序中第5-2个元素
        std::nth_element(nums.begin(),nums.begin()+nums.size()-k,nums.end());
        return nums[nums.size()-k];
    }
    int partition(vector<int>::iterator begin, vector<int>::iterator end)
    {
        int pivotIndex = std::rand()%std::distance(begin,end);
        int pivot = *(begin+pivotIndex);
        std::iter_swap(begin, begin+pivotIndex);
        vector<int>::iterator m = begin;
        for(auto iter = begin+1; iter != end; iter++)
        {
            if(*iter > pivot)
            {
                iter_swap(++m, iter);
            }
        }
        std::iter_swap(begin, m);        
        return std::distance(begin, m);
    }
    void findKthByPart(vector<int>::iterator first, vector<int>::iterator last, int k0)
    {   
        if(first == last)return;
        int m = partition(first, last);
        if( m == k0 ) return;
        else if( k0 < m )
            findKthByPart(first, first+m, k0);
        else if( m < k0 )
            findKthByPart(first+m+1, last, k0-m-1);
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        findKthByPart(nums.begin(),nums.end(),k-1);
        return nums[k-1];    
    }
    
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6}, nums2=nums;
    Solution sol;
    cout<<sol.findKthLargest2(nums,4);
    cout<<endl;
    cout<<sol.findKthLargest(nums2,4)<<endl;
    nums2={3,3,3,3,4,3,3,3,3};
    cout<<sol.findKthLargest(nums2,9)<<endl;    
    nums2={2,1};
    cout<<sol.findKthLargest(nums2,1)<<endl;
    nums2={-1,2,0};
    cout<<sol.findKthLargest(nums2,1)<<endl;
    nums2={3,2,1,5,6,4};
    cout<<sol.findKthLargest(nums2,2)<<endl;    
    return 0;
}