#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int _rob(const vector<int>& nums) {
        if(nums.size() == 1) return nums[0];  
        int *dp = new int[nums.size()+1]{0};
        dp[1] = nums[0];
        dp[2] = nums[1];
        int res = max(dp[1],dp[2]);
        for(int i = 3;i <= nums.size();++i){
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i-1];
            res = max(dp[i],res);
        }
        return res;
    }   
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        vector<int> vec1{nums.begin()+1,nums.end()},vec2{nums.begin(),nums.end()-1};
        return max(_rob(vec1),_rob(vec2));
    }
};