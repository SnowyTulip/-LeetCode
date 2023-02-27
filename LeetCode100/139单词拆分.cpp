#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301]{false};
        dp[0] = true;
        for(int j = 0;j <= s.size();++j){
            for(int i = 0;i < wordDict.size();++i){
            if(j >= wordDict[i].size()&&dp[j - wordDict[i].size()])
                if(wordDict[i] == s.substr(j - wordDict[i].size(),wordDict[i].size()))
                    dp[j] = true;
            }
        }
        return dp[s.size()];
    }
};