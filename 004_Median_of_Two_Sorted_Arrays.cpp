#include "struct_define.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}(); 

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        bool jiou = (nums1.size()+nums2.size()) % 2 ? 1 : 0;//1ji 0ou

        int pos = (nums1.size()+nums2.size())/2,posi = pos-1;
        int index = -1, i = 0, j = 0, cur = 0, res = 0, resi = 0;
        while (i < nums1.size() && j < nums2.size())
        {
          if(nums1[i] < nums2[j])
          {            
            cur = nums1[i];
            i++;
          }
          else// if(nums[1] )
          {            
            cur = nums2[j];
            j++;
          }
          index++;
          if(index == posi)
          {
            resi = cur;
          }
          else if( index == pos)
          {
            res = cur;
            if(jiou == 1)
            return res;
            else 
            return (res+resi)/2.0;
          }
        }
        while (i < nums1.size())
        {
          
          cur = nums1[i];
          i++;
          index++;
          if(index == posi)
          {
            resi = cur;
          }
          else if( index == pos)
          {
            res = cur;
            if(jiou == 1)
            return res;
            else 
            return (res+resi)/2.0;
          }
        }
        while (j < nums2.size())
        {          
          cur = nums2[j];
          j++;
          index++;
          if(index == posi)
          {
            resi = cur;
          }
          else if( index == pos)
          {
            res = cur;
            if(jiou == 1)
            return res;
            else 
            return (res+resi)/2.0;
          }
        }        
                
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> a = {1,2,3},b={4,4,5};
  cout<<sol.findMedianSortedArrays(a,b)<<endl;
  return 0;
}