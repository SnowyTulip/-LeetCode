#include<vector>
#include <algorithm>
using namespace std;
class Solution {
    vector <vector<int>> result;
    vector <int> path;
    int sum = 0;
    void backtracking(vector<int>& candidates,int target,int start){
        if(sum >= target){
            if(sum == target)
                result.push_back(path);
            return;
        }
        else{
            for(int i = start;i < candidates.size();++i){
                if(i > start && candidates[i] == candidates[i-1])
                    continue;
                else{
                    sum += candidates[i];
                    path.push_back(candidates[i]);

                    backtracking(candidates,target,i+1);

                    sum -= candidates[i];
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return result;

    }
};