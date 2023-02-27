#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int,int> dic;
        int cnt = 0,max_val = 0;
        dic[0] = -1;
        for(int i = 0;i < nums.size();++i){
            cnt -= 1;
            if(nums[i]) cnt += 2;
            if(dic.count(cnt)) 
                max_val = max(max_val,i - dic[cnt]);
            else
                dic[cnt] = i;
        }
        return max_val;
    }
};