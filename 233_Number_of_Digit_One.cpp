#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int get_one_count(int number)
    {
        int cnt = 0;
        while( number != 0)
        {
            int cur_dig = number % 10;
            number = number / 10;
            if(cur_dig == 1)
                ++cnt;
        }
        return cnt;
    }
    int countDigitOne(int n) {
        int count = 0;
        for(int i = 1 ; i <= n; i++)
        {
            cout<<i<<endl;
            count += get_one_count(i);
        }
        return count;
    }
    
};

int main(int argc, char const *argv[])
{

    Solution s;
    cout<<s.countDigitOne(824883);
	return 0;
}