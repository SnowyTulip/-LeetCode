#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> dict;
        vector <int> result;
        for(int i = 0; i < nums.size();++i){
            dict[nums[i]] = i;
        }
        for(int j = 0;j < nums.size();++j){
            if(dict.count(target - nums[j])){
                result.push_back(j);
                result.push_back(dict[target - nums[j]]);
                return result;
            }
        }
        return result;
    }
};
int main(){
    vector <int> a = {3,2,4};
    Solution s;
    s.twoSum(a,6);
}