#include "bitc++.hpp"
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int now = 1,max = 1;
        for(int i = 0;i < n -1;++i){
            if(nums[i+1] > nums[i])
                now ++;
            else
                now = 1;
            max = now > max ? now : max; 
        }
        return max;
    }
};
int main(){
    return 0;
}