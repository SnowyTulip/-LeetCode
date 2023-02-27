#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector <int> path;
    int sum = 0;
    // bool can_use[10]{1,1,1,1,1,1,1,1,1,1};
    void backtracking(int k,int n,int index){
        if(path.size() == k || sum > n){
            if(sum == n)
                result.push_back(path);
            return;
        }
        else{
            for(int i = index;i <= 9;++i){
                // can_use[i] = false;
                path.push_back(i);
                sum += i;
                backtracking(k,n,i+1);
                // can_use[i] = true;
                path.pop_back();
                sum -= i;
                
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return result;
    }
};