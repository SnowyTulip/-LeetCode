#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int **dp = new int* [word1.size()+1];
        for(int i = 0;i <= word1.size();++i) dp[i] = new int[word2.size()+1]{0};
        for(int i = 1;i <= word1.size();++i)
            for(int j = 1;j <= word2.size();++j)
                dp[i][j] = word1[i-1] == word2[j-1]?
                        (dp[i-1][j-1] + 1): max(dp[i-1][j],dp[i][j-1]); 

        return word1.size()+word2.size() - 2*dp[word1.size()][word2.size()];
    }
};