#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int>result;
        int n = nums.size();
        int index = 0;
        for(int i = 0;i < n;++i){
            if(nums[i] < 0)
                index ++;
            nums[i] = nums[i] *nums[i];
        }
        int pre = index -1, next = index;
        while(pre >= 0 && next < n){
            if(nums[pre] < nums[next]){
                result.push_back(nums[pre]);
                pre --;
            }
            else{
                result.push_back(nums[next]);
                next++;
            }
        }
        for(int i = pre; i >= 0; -- i)
            result.push_back(nums[i]);
        for(int j = next; j < n; ++ j)
            result.push_back(nums[j]);
        return result;
    }
};