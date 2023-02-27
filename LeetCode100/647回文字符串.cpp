#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int m = s.size();
        bool **dp = new bool *[m];
        for(int i = 0;i < m;++i) dp[i] = new bool[m]{0};
        int cnt = 0;
        for(int i = m-1;i >= 0;i--){
            for(int j = i;j < m;j++){
                if(s[i] == s[j]){
                    if(j - i <= 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                cnt = dp[i][j] ? cnt+1:cnt;
            }
        }
        return cnt;
        
    }
};
int get_count (string s,int l,int r) {
    int cnt = 0;
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        cnt ++;
        l--;
        r++;
    }
    return cnt;
}
class Solution_ {
public:
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0;i < s.size();++i){
            result += get_count(s,i,i);
            result += get_count(s,i,i+1);
        }
        return result;
    }
};