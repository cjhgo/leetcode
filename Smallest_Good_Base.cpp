#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
	//std::vector<int> nums={1,3,6,2,5,8,7,11};
	std::string s="4681";
	unsigned long long int x = std::stoll(s);
	unsigned long long int y=2;
	unsigned long long int value=0;

	while(true)
	{	
		value = 0;
		// if ((x-1)%y != 0)
		// {
		// 	// std::cout<<"hit once"<<std::endl;
		// 	++y;
		// 	continue;
		// }
		// std::cout<<y<<std::endl;
		size_t max_pow=std::ceil(std::log(x)/std::log(y));
		// if (pow(y,max_pow < x))
		// {
		// 	++y;
		// 	continue;
		// }
		for (int i = 0; i <= max_pow ; ++i)
		{
			value += pow(y,i);
			if (value >= x)
			{
				break;
			}
		}
		if (value == x)		
			break;
		else
			++y;

		
	}
	std::cout<<y<<"\t"<<value;
	return 0;
}