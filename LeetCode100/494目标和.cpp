#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, m = nums.size();
        for (auto& i : nums) sum += i;
        int** dp = new int* [m];
        for (int i = 0; i < m; ++i) dp[i] = new int[2 * sum + 1]{0};
        int offset = sum;
        dp[0][nums[0] + offset] += 1;
        dp[0][-nums[0] + offset] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = -sum; j <= sum; ++j) {
                if (j - nums[i] + offset >= 0 && dp[i - 1][j - nums[i] + offset])
                    dp[i][j+offset]+= dp[i - 1][j - nums[i] + offset];
                if (j + nums[i] + offset <= 2 * sum && dp[i - 1][j + nums[i] + offset])
                    dp[i][j+offset]+= dp[i - 1][j + nums[i] + offset];   
            }
        }
        if (target > sum || target < -sum)
            return 0;
        return dp[m - 1][target+offset];
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, m = nums.size();
        for (auto& i : nums) sum += i;
        int t = (target+sum)/2;
        if(abs(target) > sum || (target + sum) %2)
            return 0;
        int *dp = new int[t + 1]{0};
        dp[0] = 1;
        for(int i = 0;i < m;++i){
            for(int j = t;j >= nums[i];--j){
                dp[j] += dp[j - nums[i]]; 
            }
        }
        return dp[t];
    }
};