#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int *dp = new int [prices.size()+1]{0};
        int min_val = prices[0] ,profit = 0,max_val = prices[prices.size()-1];
        for(int i = 1;i < prices.size();++i){
            profit = max(profit,prices[i] - min_val);
            dp[i] = profit;
            min_val = min(min_val,prices[i]);
        }
        profit = 0;
        for(int i = prices.size()-2;i >= 0;--i){
            profit = max(profit,max_val - prices[i]);
            dp[i] += profit;
            max_val = max(max_val,prices[i]);
        }
        for(int i = 0;i < prices.size();++i)
            profit = max(profit,dp[i]);
        return profit;
    }
};