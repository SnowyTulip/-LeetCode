#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = 0 ;
        while (left <= right) {
            mid = (left + right +1) / 2;
            if(right - left <= 1)
                break;
            if (nums[mid] > nums[0])
                left = mid;
            else if (nums[mid] < nums[0])
                right = mid;
            
        }
        if (target < nums[0]) {
            left = mid;
            right = n - 1;
        }
        else {
            right = mid;
            left = 0;
        }
        int result = -1;
        while (left <= right) {
            mid = (right  + left) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid -1;
            else {
                result = mid;
                break;
            }
        }
        return result;
    }
};