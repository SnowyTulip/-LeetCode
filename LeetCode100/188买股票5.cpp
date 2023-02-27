#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || k == 0) return 0;
        int **dp = new int* [n];
        for(int i = 0;i < n;++i) dp[i] = new int[2*k+1]{0};
        for(int i = 1;i <= k;++i)
            dp[0][i] = - prices[0];
        for(int i = 1;i < n;++i){
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
            for(int j = 2;j <= k;++j)//对买入j次状态进行操作
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1+k] - prices[i]);
            
            for(int j = k+1;j <= 2*k;++j)//对卖出j次的状态操作
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-k] + prices[i]);
            
        }  
        return dp[n-1][2*k];
    }
};