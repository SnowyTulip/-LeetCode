#include "bitc++.hpp"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n];
        for(int i = 0;i < n;++i) dp[i] = 1;
        dp[0] = 1;
        int max = 1,cm = 1;
        for(int i = 1;i < n;++i){
            for(int j = i; j >= 0; --j){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            max = max > dp[i]?max : dp[i];
        }
        return max;
    }
};
int main(){
    Solution s;
    vector <int> sn{10,9,2,5,3,7,101,18};
    s.lengthOfLIS(sn);
    return 0;
}