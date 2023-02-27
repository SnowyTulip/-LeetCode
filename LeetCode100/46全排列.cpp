#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    bool can_use[7];
    void backtracking(vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        else{
            for(int i = 0;i < nums.size();++i){
                if(can_use[i]){
                    can_use[i] = false;
                    path.push_back(nums[i]);
                    backtracking(nums);
                    path.pop_back();
                    can_use[i] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0;i < 7;++i) can_use[i] = 1;
        result.clear();
        path.clear();
        backtracking(nums);
        return result;
    }
};