#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool** dp = new bool* [n];
        for (int i = 0; i < n; ++i) dp[i] = new bool[n] {0};
        int left = 0;
        int max = 0;
        for (int i = n; i >= 0; --i)
            for (int j = i; j < n; ++j)
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] && j - i + 1 > max) {
                        left = i;
                        max = j - i + 1;
                    }
                }

        return s.substr(left, max);
    }
};
int main() {
    string ss = "aacabdkacaa";
    Solution s;
    cout << s.longestPalindrome(ss);
    return 0;
}