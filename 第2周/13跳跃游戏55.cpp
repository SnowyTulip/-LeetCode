#include <vector>
#include <iostream>
using namespace std;
//[2,3,1,1,4]
//[3,2,1,0,4]
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Max = nums[0];
        int n = nums.size();
        for(int i = 1;i < n && Max >= i && Max < n-1;++i){
            Max = Max > i + nums[i] ? Max:i + nums[i]; 
        }
        return Max >= n-1;
    }
};
int main(){
    Solution s;
    vector <int> a{2,3,1,1,4};
    s.canJump(a);
}