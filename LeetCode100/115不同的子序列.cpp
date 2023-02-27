#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        double**dp = new double* [s.size()];
        for(int i = 0;i < s.size();++i) dp[i] = new double[t.size()];

        for(int i = 0;i < s.size(); ++i){
            for(int j = 0;j < t.size();++j){
                if(s[i] == t[j]){
                    if(i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if(i == 0)
                        dp[i][j] = 0;
                    else if(j == 0)
                        dp[i][j] = dp[i-1][j] + 1;
                    else
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    if(i == 0 && j == 0)
                        dp[i][j] = 0;
                    else if(i == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return int(dp[s.size()-1][t.size()-1]);
    }
};

int main(){
    return 0;
}