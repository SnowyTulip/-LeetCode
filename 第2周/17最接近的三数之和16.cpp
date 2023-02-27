#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // int result = 0;
        int L,R,num = nums[0] + nums[1]+nums[2];
        int i = 0;
        while(i < n){
            L = i + 1;
            R = n -1;
            while(L < R){
                num = abs(num - target) < abs(nums[i] +nums[L]+nums[R]-target)?num:nums[i] +nums[L]+nums[R];
                if(nums[i] +nums[L]+nums[R] < target){
                    L++;
                }
                else if(nums[i] + nums[L]+nums[R] > target){
                    R--;
                }
                else{
                    return target;
                }
            }
            while(i + 1 < n && nums[i] == nums[i+1])
                i++;
            i++;
        }
        return num;
    }
};