# include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,right = n-1;
        int mid;
        while(left <= right){
            mid = left/2 + right/2;
            if(nums[mid] > nums[0])
                left = mid;
            else if(nums[mid] < nums[0])
                right = mid;
            else
                break;
        }
        if(target < nums[0]){
            left = mid;
            right = n -1;
        }
        else{
            right = mid;
            left = 0;
        }
        int result = -1;
        while(left<=right){
            mid = right/2 + left /2;
            if(target > nums[mid])
                left = mid;
            else if(target < nums[mid])
                right = mid;
            else{
                result = mid;
                break;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector <int> num = {4,5,6,7,0,1,2};
    s.search(num,0);
    return 0;
}