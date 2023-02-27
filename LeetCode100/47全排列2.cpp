#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    bool can_use[8];
    void backtracking(vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        else{
            bool can_use_val[21];
            for(int i = 0;i < 21;++i) can_use_val[i] = true;
            for(int i = 0;i < nums.size();++i){
                if(can_use_val[nums[i]+10]){
                    if(can_use[i]){
                        can_use_val[nums[i]+10] = false;
                        can_use[i] = false;
                        path.push_back(nums[i]);
                        backtracking(nums);
                        path.pop_back();
                        can_use[i] = true;
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i = 0;i < 8;++i) can_use[i] = 1;
        result.clear();
        path.clear();
        backtracking(nums);
        return result;
    }
};