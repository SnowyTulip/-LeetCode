#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        int **dp = new int*[m+1];
        for(int i = 0;i <= m;++i) dp[i] = new int[n+1]{0};
        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                if(text1[i-1] == text2[j-1])
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
    string text1 = "abcde";
    string text2 = "ace";
    ss.longestCommonSubsequence(text1,text2);
    return 0;
}