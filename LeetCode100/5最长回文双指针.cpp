#include <iostream>
#include <algorithm>
using namespace std;
int solve(string& s, int l, int r) {
    int count = r - l - 1;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        count += 2;
        l--;
        r++;
    }
    return count;
}
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max = 0, cnt;
        int left = 0;
        for (int i = 0; i < n; ++i) {
            cnt = solve(s, i, i);
            if (cnt > max) {
                left = i - cnt / 2;
                max = cnt;
            }
            cnt = solve(s, i, i + 1);
            if (s[i] == s[i + 1] && cnt > max) {
                left = i+1 - cnt / 2;
                max = cnt;
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