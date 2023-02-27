#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3)  return n-1;
        int dp[60]{0};
        for(int i = 0;i <= n;++i) dp[i] = i;
        for(int i = 4;i <= n;++i){
            for(int j = 1;j < i;++j){
                dp[i] = max(dp[i],j*dp[i-j]); 
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n-1;
        int re = n % 3;
        if(re == 0)
            return pow(3,n/3);
        else if(re == 1)
            return 4 * pow(3,(n-4)/3);
        else
            return 2 * pow(3, (n-2)/3 );
    }
};