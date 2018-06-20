#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
unsigned long long int mypow(unsigned long long int base, size_t pow)
{
	unsigned long long int temp = 1;
	for (int i = 0; i < pow; ++i)
	{
		temp *= base;
	}
	return temp;
}

unsigned long long int get_n_at_base_with_l(unsigned long long int base, size_t len)
{
	unsigned long long int sum = 1;
	for (size_t i = 1; i < len; ++i)
	{
		unsigned long long int temp = mypow(base, i);
		if (std::numeric_limits< unsigned long long >::max() - temp < sum)
		{
			break;
		}
		else
			sum += temp;
	}
	return sum;
}
class Solution {
public:
    string smallestGoodBase(string n) {
    	unsigned long long int x = std::stoll(n);
    	unsigned long long int y=2;
    	unsigned long long int value=0;

    	size_t max_pow=std::ceil(std::log(x)/std::log(2));
    	size_t i = max_pow;
    	for (; i > 0; --i)
    	{
    		unsigned long long int begin = y;
    		unsigned long long int end = std::numeric_limits< unsigned long long >::max() - y;	
    		
    		while(begin <= end)
    		{

    			y = (begin+end)/2;
    			value = get_n_at_base_with_l(y, i);
    			if (value > x)
    			{
    				end = y-1;
    			}
    			else if ( value == x)
    			{
    				break;
    			}
    			else if ( value < x)
    			{
    				begin = y+1;
    			}
    		}
    		if (value == x)
    			break;
    	}    	
        return std::to_string(y);
    }
};


int main(int argc, char const *argv[])
{
	//std::vector<int> nums={1,3,6,2,5,8,7,11};
	std::string n="2251799813685247";
	unsigned long long int x = std::stoll(n);
	unsigned long long int y=2;
	unsigned long long int value=0;

	size_t max_pow=std::ceil(std::log(x)/std::log(2));
	size_t i = max_pow;
	for (; i > 0; --i)
	{

		std::cout<<i<<"------!\n";
		std::cout<<std::pow(x, 1.0/i)<<"\t"<<std::pow(x,1.0/(i-1))<<std::endl;
		unsigned long long int begin = y;
		unsigned long long int end = std::numeric_limits< unsigned long long >::max() - y;	
		
		while(begin <= end)
		{

			y = (begin+end)/2;
			if (y == 1125899906842624 and i == 52)
			{
				std::cout<<" break at here\n";
			}
			std::cout<<begin<<"\t"<<y<<"\t"<<end<<std::endl;
			value = get_n_at_base_with_l(y, i);
			std::cout<<y<<"\t"<<value<<std::endl<<std::endl;
			if (value > x)
			{
				end = y-1;
			}
			else if ( value == x)
			{
				break;
			}
			else if ( value < x)
			{
				begin = y+1;
			}
		}
		if (value == x)
			break;
	}
	std::cout<<i<<"\t"<<y<<"\t"<<value;
	return 0;
}