#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0,target;
        for(auto i:stones) sum += i;
        target  = sum/2; 
        int *dp = new int[target + 1]{0};
        for(int i = 0;i < stones.size();++i){
            for(int j = target;j >= stones[i];--j)
                dp[j] = max( dp[j], dp[j-stones[i]] + stones[i]);
        }
        return (sum- dp[target]) - dp[target];
    }
};