#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int **dp = new int* [m+1];
        for(int i = 0;i <= m;++i)dp[i] = new int[n+1]{0};
        for(int i = 1;i <= m;++i){
            for(int j = 1; j <= n;++j){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution ss;
    return 0;
}