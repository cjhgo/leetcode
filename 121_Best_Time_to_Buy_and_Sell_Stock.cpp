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
    int solve(vector<int>& prices, size_t l, size_t r)
    {
        if( l == r)return 0;
        int max_value = prices[l];
        bool is_descending = true;
        for(size_t i = l+1; i <= r; i++)
        {
            if( prices[i] >= prices[i-1])is_descending = false;
            if( prices[i] > max_value)
            max_value = prices[i];
        }
        if( is_descending)return 0;
        int buy_at_l = max_value - prices[l];
        int not_buy_at_l = solve(prices, l+1, r);
        return max(buy_at_l, not_buy_at_l);
    }
    int maxProfit2(vector<int>& prices) 
    {
        if( prices.size() > 0)
            return solve(prices, 0, prices.size()-1);
        else
            return 0;
    }
    int maxProfit(vector<int>& prices) 
    {
        int MinPrice = INT32_MAX;
        int MaxProfit = 0;
        for(auto e : prices)
        {
            if( e < MinPrice)
                MinPrice = e;
            else if( (e - MinPrice) > MaxProfit)
                MaxProfit = e - MinPrice;
        }
        return MaxProfit;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,4,3,1};

    Solution sol;
    cout<<sol.maxProfit(prices)<<endl;
    cout<<sol.maxProfit(prices2)<<endl;
    return 0;
}