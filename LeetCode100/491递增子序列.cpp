#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,int father_val,int start){
        if(path.size() >= 2)
            result.push_back(path);
        if( start >= nums.size())
            return;
        else{
            unordered_set <int> uset;
            for(int i = start;i < nums.size();++i){
                if(nums[i] >= father_val && uset.count(nums[i]) == 0){
                    uset.emplace(nums[i]);
                    path.push_back(nums[i]);
                    backtracking(nums,nums[i],i+1);
                    path.pop_back();
                }
            }
            uset.clear();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums,-200,0);
        return result;
    }
};