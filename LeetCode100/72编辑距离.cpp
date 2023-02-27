#include <iostream>
using namespace std;
int min3(int a,int b,int c){
    a = a < b ? a : b;
    c = c < a ? c : a;
    return c;
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        int **dp = new int* [word1.size()+1];
        for(int i = 0;i <= word1.size();++i) dp[i] = new int[word2.size()+1];

        for(int i = 0;i <= word1.size();++i) dp[i][0] = i;//删除i次
        for(int j = 0;j <= word2.size();++j) dp[0][j] = j;//增加j次

        for(int i = 1;i <= word1.size();++i){
            for(int j = 1;j <= word2.size();++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = min3(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};