#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        int *dp = new int[n+1]{0};
        dp[0] = 0;
        vector <int> res;
        for(int i = 0;i <= n;++i){
            dp[i] = i%2? dp[i-1]+1 : dp[i/2];
            res.push_back(dp[i]);
        }
        return res;
    }
};