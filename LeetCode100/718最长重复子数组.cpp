#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int **dp = new int*[m+1];
        for(int i = 0;i <= m;++i) dp[i] = new int[n+1]{0};
        int max = 0;
        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                max = max > dp[i][j] ? max: dp[i][j];
            }
        }
        return max;
    }
};
int main() {
    Solution ss;
    vector <int> s1{ 1,2,3,2,1 };
    vector <int>s2{ 3,2,1,4 };
    ss.findLength(s1, s2);
    return 0;
}