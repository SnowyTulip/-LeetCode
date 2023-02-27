#include <vector>
#include <map>
using namespace std;
#include <algorithm>
//[-1,3,1,2,-1,-4]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> dict;
        vector<int> pack;
        vector<vector<int>> ans;
        int n = nums.size();
        int index = 0;
        for(int i = 0;i < n;++i){
            dict[nums[i]] = i;
            if(nums[i] <= 0)
                index++;
        }
        int i = 0,j = 0;
        while(i < index){
            j = i +1;
            while(j < n){
                if(dict.find(-(nums[i]+nums[j])) != dict.end() &&dict[-(nums[i]+nums[j])] > j){
                    pack.push_back(nums[i]);
                    pack.push_back(nums[j]);
                    pack.push_back(-(nums[i]+nums[j]));
                    ans.push_back(pack);
                    pack.clear();
                }
                j++;
                while(  j < n && nums[j] == nums[j-1])
                j++;
            }
            i++;
            while(i >= 1 && i < n&& nums[i] == nums[i-1])
                i++;
        }
        return ans;
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> pack;
        vector<vector<int>> ans;
        int n = nums.size();
        int index = 0;
        int L = 0, R = n -1;
        while(L < R){
            index = L+1;
            while(index < R){
                if(nums[index]+nums[L]+nums[R] < 0)
                    index++;
                else if(nums[index]+nums[L]+nums[R] > 0){
                    while(R-1>=0 && nums[R-1] == nums[R])
                        R--;
                    R--;
                    break;
                }
                else{
                    pack.clear();
                    pack.push_back(nums[L]);
                    pack.push_back(nums[index]);
                    pack.push_back(nums[R]);
                    ans.push_back(pack);
                }
            }
            if(index == R){
                while(L+1 < n&&nums[L] == nums[L+1])
                    L++;
                L++;
            }
        }
        return ans;
    }
};
