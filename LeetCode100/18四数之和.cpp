#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <vector<int>> res;
        sort(nums.begin(), nums.end());
        if (n < 4) return res;
        long long left = 0, mid1, mid2, right = n - 1;
        double sum;
        for (int i = 0; i < n - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = n - 1; j >= 3; --j) {
                if (j != n - 1 && nums[j] == nums[j + 1])
                    continue;
                mid1 = i + 1;
                mid2 = j - 1;
                while (mid1 < mid2) {
                    sum = double(nums[i]) + nums[j] + nums[mid1] + nums[mid2];
                    if (sum > target) {
                        mid2--;
                    }
                    else if (sum < target) {
                        mid1++;
                    }
                    else {
                        res.push_back(vector<int> {nums[i], nums[mid1], nums[mid2], nums[j]});
                        mid1++;
                        mid2--;
                        while (mid1 < mid2 && nums[mid1] == nums[mid1 - 1]) mid1++;
                        while (mid1 < mid2 && nums[mid2] == nums[mid2 + 1]) mid2--;
                    }
                }
            }
        }
        return res;
    }
};