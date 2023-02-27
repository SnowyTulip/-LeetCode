#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int>& x,vector<int>& y){
	return x[0] < y[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int count = 0,indexi = points[0][0],indexj = points[0][1];
        for(int i = 1;i < points.size();++i){
            if(indexj >= points[i][0]){
                indexi = indexi > points[i][0] ? indexi:points[i][0];
                indexj = indexj < points[i][1] ? indexj:points[i][1];
            }
            else{
                indexi = points[i][0];
                indexj = points[i][1];
                count++;
            }
        }
        return count;
    }
};