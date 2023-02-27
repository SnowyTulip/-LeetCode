#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,target;
        for(auto &i:nums) sum +=i;
        if(sum % 2) return false;
        target = sum / 2;
        bool *dp = new bool[target+1]{0};
        dp[0] = 1;
        for(int i = 0;i < nums.size();++i)
            for(int j = target;j >= nums[i];--j)
                dp[j] |= dp[j - nums[i]];
        return dp[target];
    }
};