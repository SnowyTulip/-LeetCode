#include <vector>
using namespace std;
int min(int a,int b){
    return a < b ? a:b; 
}
int max(int a,int b){
    return a > b ? a:b;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n <= 2)
            return min(height[0],height[1]);
        int indexi = 0 ,indexj = n-1;
        int result = min(height[indexi],height[indexj]);
        int sumi,sumj;
        while(indexi!=indexj){
            sumi = min(height[indexi-1],height[indexj])*(indexj - indexi+1);
            sumj = min(height[indexi],height[indexj+1])*(indexj - indexi+1);
            result = max(result,max(sumi,sumj));
            if(height[indexi] < height[indexj])
                indexi ++;
            else
                indexj --;
        }
        return result;
    }
};