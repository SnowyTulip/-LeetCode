#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        int **dp = new int*[m];
        for(int i = 0;i < m;++i) {
            dp[i] = new int[m]{0};
            dp[i][i] = 1;
        }
        for(int i = m-1;i >= 0;i--){
            for(int j = i+1;j < m;++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2; 
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][m-1];
    }
};