#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <queue>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}();

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for(int i = 0; i < nums.size();i++)
      {
        if( i >= k)
        {
          topk.push(nums[i]);
          topk.pop();
        }else topk.push(nums[i]);
      }
    }
    
    int add(int val) {
      topk.push(val);
      if(topk.size() == k+1)topk.pop();
      return topk.top();
    }
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int> > topk;
};

int main(int argc, char const *argv[])
{
  // Solution sol;
  return 0;
}