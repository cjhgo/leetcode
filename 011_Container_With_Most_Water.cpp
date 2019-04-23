#include"struct_define.h"
#include<iostream>
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
    int maxArea(vector<int>& height) 
    {
      int i = 0, j = height.size()-1, maxArea=0;
      while( i <j )    
      {
        int low = height[i] < height[j] ? i : j;
        int current = (j-i)*height[low];
        printf("%d\t%d\t%d\t%d\n",i,j,height[low], current);
        if(current > maxArea) maxArea=current;
        if( low == i)
        {
          i++;
        }
        else
        {
          j--;
        }        
      }
      return maxArea;
    }
};
int main(int argc, char const *argv[])
{
  Solution sol;
  vector<int> height{1,8,6,2,5,4,8,3,7};
  cout<<sol.maxArea(height);
  return 0;
}
