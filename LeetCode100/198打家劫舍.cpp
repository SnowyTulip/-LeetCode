#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m == 1)
            return nums[0];
        int *dp = new int[m+1]{0};
        dp[1] = nums[0]; 
        dp[2] = max(nums[0],nums[1]);
        for(int i = 3;i <= m;++i){
            dp[i] = max(dp[i-2],dp[i-3])+nums[i-1];
        }
        return max(dp[m],dp[m-1]);
    }
};
