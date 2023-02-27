#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map <int,int> dic2;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if(dic2.count(nums3[i] +nums4[j]) == 0)
                    dic2[nums3[i] + nums4[j]] = 0;
                dic2[nums3[i] + nums4[j]]++;
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if( dic2.count(-(nums1[i] + nums2[j])))
                    cnt += dic2[-(nums1[i] + nums2[j])];
            }
        }
        return cnt;
    }
};