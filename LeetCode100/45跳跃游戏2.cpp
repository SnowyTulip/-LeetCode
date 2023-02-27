#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int cnt = 0;
        int far = 0,far_f = far;
        while(far < nums.size() -1){
            for(int i = cur;i <= far_f;++i){
                far = max(far,nums[i] + i);
            }
            cur = far_f + 1;
            far_f = far;
            cnt++;
        }
        return cnt;
    }
};