#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
		std::sort(nums.begin(),nums.end());
		size_t index = nums.size()/2;
		int median=nums[index];
		int sum = 0;
		for (auto a : nums)
		{
			sum += std::abs(a-median);
		}
		return sum;
    }
};


int main(int argc, char const *argv[])
{
	//std::vector<int> nums={1,3,6,2,5,8,7,11};
	std::vector<int> nums={4,5,6,7};
	std::sort(nums.begin(),nums.end());
	for (auto a : nums)
	{
		std::cout<<a<<std::endl;
	}
	std::cout<<std::endl;
	size_t index = nums.size()/2;
	int median=nums[index];
	int sum = 0;
	for (auto a : nums)
	{
		sum += std::abs(a-median);
	}
	std::cout<<sum;
	return 0;
}