#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp = new int[amount+1]{0};
        for(int i = 1;i <= amount;++i)
            dp[i] = 100000;
        for(int i = 0;i < coins.size();++i){
            for(int j = coins[i];j <= amount;++j){
                if(dp[j - coins[i]] != 100000)
                    dp[j] = min(dp[j - coins[i]] + 1,dp[j]);
            }
        }
        return dp[amount] == 100000 ? int(-1) : dp[amount];
    }
};