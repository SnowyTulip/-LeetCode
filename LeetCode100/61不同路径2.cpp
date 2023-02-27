#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        int **dp = new int*[m+1];
        for(int i = 0;i <= m;++i) 
            dp[i] = new int[n+1]{0};
        dp[1][0] =1;
        for(int i = 1;i <= m;++i){
            for(int j = 1; j <= n;++j){
                dp[i][j] = obstacleGrid[i-1][j-1] == 1 ? 0 : dp[i-1][j] + dp[i][j-1]; 
            }
        }
        return dp[m][n];

    }
};