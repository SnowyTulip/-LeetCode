#include <algorithm>
#include <vector>
using namespace std;
bool cmp(vector<int>& a,vector<int>& b){
    return a[0] < b[0];
}
int max(int a,int b){
    return a > b ? a : b;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        vector<int> pack;
        vector<vector<int>> result;
        int L = -1,R = -1;
        int index = 0;
        while(index < n){
            L = intervals[index][0];
            R = intervals[index][1];
            index++;
            while(index < n && R >= intervals[index][0]){
                R = max(intervals[index][1],R);
                index++;
            }
            pack.clear();
            pack.push_back(L);
            pack.push_back(R);
            result.push_back(pack);
        }
        return result;
    }
};