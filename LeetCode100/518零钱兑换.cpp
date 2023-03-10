#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int *dp = new int[amount+1]{0};
        dp[0] = 1;
        for(int i = 0;i < coins.size();++i){
            for(int j = coins[i]; j <= amount;++j){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
        
    }
};