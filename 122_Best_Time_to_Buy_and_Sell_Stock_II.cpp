#include<iostream>
#include<vector>
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
    int maxProfit(vector<int>& prices) 
    {
        int i = 0;
        int p_size=prices.size();
        int profit=0;
        while(i < p_size)
        {            
            for(; i < p_size-1;i++)
            {
                if(prices[i] >= prices[i+1])
                    continue;
                else
                    break;
            }
            if( i == (p_size-1) and prices[i] >= prices[i+1] )
            {                
                break;
            }
            else//i < p_size-1 or (i == p_size-1 and ascending)
            // then there must exist one transaction
            {
                int buy_price = prices[i++];
                for(; i < p_size;i++)
                {
                    if(prices[i] > prices[i-1])
                        continue;
                    else
                        break;
                }
                profit += (prices[i-1] - buy_price);
            }            
        }
        return profit;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    vector<int> prices2={1,2,3,4,5};    
    cout<<sol.maxProfit(prices)<<endl;
    cout<<sol.maxProfit(prices2)<<endl;
    return 0;
}