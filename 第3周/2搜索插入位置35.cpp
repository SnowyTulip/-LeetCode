#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0,R = n - 1,mid;
        // int result = -1;
        while(L <= R){
            mid = (L+R)/2;
            if(nums[mid] > target)
                R = mid - 1;
            else if(nums[mid] < target)
                L = mid + 1;
            else
                return mid;
        }
        return target > nums[mid] ? mid + 1: mid;
    }
};