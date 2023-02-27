#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> vec;
        vector<vector<int>>* dp = new vector<vector<int>>[target+1];
        dp[0].push_back(vec);
        for(auto &num : candidates){
            for(int j = num;j <= target;++j){
                for(auto item:dp[j-num]){
                    item.push_back(num);
                    dp[j].push_back(item);
                }
            }
        }
        return dp[target]; 
    }
};
class Solution {
private:
    vector <vector<int>> result;
    vector <int> path;
    int sum = 0;
    void backtracking(vector <int>& candidates,int target,int start){
        if(sum >= target){
            if (sum == target)
                result.push_back(path);
            return;
        }
        else{
            for(int i = start;i < candidates.size();++i){
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates,target,i);
                path.pop_back();
                sum -= candidates[i];
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};