#include <vector>
using namespace std;
int bin_search(vector<int>& nums, int target){
    int n = nums.size();
    int L = 0,R = n - 1,mid;
    while(L <= R){
        mid = (L + R)/2;
        if(nums[mid] > target)
            R = mid - 1;
        else if(nums[mid] < target)
            L = mid + 1;
        else 
            break;
    }
    return mid;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums.size() == 0)
            return {-1,-1};
        int tag1 ,tag2;
        tag1 = bin_search(nums,target - 1);
        tag2 = bin_search(nums,target + 1);
        vector<int> result;
        while( tag1 < n && nums[tag1] < target)
            tag1++;
        while(tag2 >= 0 && nums[tag2] > target)
            tag2--;
        if(tag1 > tag2)
            result = {-1,-1};
        else
            result = {tag1,tag2};
        
        return result;

    }
};