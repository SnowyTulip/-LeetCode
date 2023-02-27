#include <iostream>
#include <vector>
using namespace std;
class Solution_ {
public:
    int maxSubArray(vector<int>& nums) {
        int *dp = new int[nums.size()];
        dp[0] = max_f(0,nums[0]); 
        int ma = dp[0];
        int mm = nums[0];
        for(int i = 1;i < nums.size();++i){
            dp[i] = max_f(dp[i-1] + nums[i],0);
            ma = ma > dp[i] ?  ma:dp[i];
            mm = max_f(mm,nums[i]);
        }
        return mm > 0 ? ma : mm;
    }
    inline int max_f(int a,int b){
        return a > b ? a : b;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0],max = nums[0];
        for(int i = 1; i < nums.size();++i){
            sum = sum > 0 ? nums[i] + sum : nums[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
};
int main(){
    return 0;
}