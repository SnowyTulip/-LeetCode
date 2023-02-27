#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector <int> path;
    void backtracking(vector<int>& nums,int start){
        res.push_back(path);
        if(start >= nums.size())
            return;
        else{
            for(int i = start;i < nums.size();++i){
                path.push_back(nums[i]);
                backtracking(nums,i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums,0);
        return res;
    }
};