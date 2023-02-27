#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]{0}; 
        int *zero = new int[strs.size()]{0};
        int *one  = new int[strs.size()]{0};
        for(int i = 0;i < strs.size();++i){
            zero[i] = count(strs[i].begin(),strs[i].end(),'0');
            one [i] = count(strs[i].begin(),strs[i].end(),'1');
        }
        for(int i = 0;i < strs.size();++i){
            for(int j = m;j >= zero[i];--j){
                for(int k = n;k >= one[i];--k){
                    dp[j][k] = max(dp[j - zero[i]][k-one[i]]+1,dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};