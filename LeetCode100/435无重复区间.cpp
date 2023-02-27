#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a,vector <int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int r = intervals[0][1],cnt = 0;
        for(int i = 1;i < intervals.size();++i){
            if(intervals[i][0] < r){
                r = min(r,intervals[i][1]);
                cnt++;
            }
            else
                r = intervals[i][1];
        }
        return cnt;
    }
};