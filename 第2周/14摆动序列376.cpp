#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 1;
        int index = 1,n = nums.size();
        int num = nums[0];
        while(index < n){
            if(num < nums[index]){
                while(index < n && num <= nums[index]){
                    num = nums[index];
                    index++;
                }
                count++;
            }
            else if(num > nums[index]){
                while(index < n && num >= nums[index]){
                    num = nums[index];
                    index++;
                }
                count++;
            }
            else
                while(index < n && num == nums[index]){
                    index++;
            }
        }
        return count;
    }
};