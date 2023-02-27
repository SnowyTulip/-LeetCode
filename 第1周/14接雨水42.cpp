# include <vector>
# include <iostream>
# include <stack>
using namespace std; 
int max(int a,int b){
    return a>b? a:b;
}
int min(int a,int b){
    return a>b ?b:a;
}
int relu(int a){
    return a > 0 ? a : 0;
}
class Solution {
public:
    int trap(vector<int>& height) {
        //动态规划
        int n = height.size();
        vector <int> max_left(n,0),max_right(n,0);
        max_left[0] = height[0];
        max_right[n-1] = height[n-1];
        for(int i = 1;i < n;++i)
            max_left[i] = max(max_left[i-1],height[i]);
        for(int i = n-2;i >= 0;--i)
            max_right[i] = max(max_right[i+1],height[i]);
        int result = 0;
        for(int i = 1;i < n - 1;++i){
            result += relu(min(max_right[i+1],max_left[i-1]) - height[i]);
        }
        return result;
    }
    int trap1(vector<int>& height) {
        //双指针
        int n = height.size();
        int left = 0,right = n-1;
        int result = 0;
        int leftmax = 0,rightmax = 0;
        while(left <= right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(leftmax < rightmax){
                result += leftmax - height[left];
                left ++;
            }
            else{
                result += rightmax - height[right];
                right--;
            }
        }
        return result;
    }
    int trap2(vector<int>& height) {
        //单调栈
        stack<int> s;
        int ans = 0;
        for(int i = 0;i < height.size();++i){
            while(!s.empty() && height[i] > s.top()){
                int top = s.top();
                s.pop();
                if(s.empty())
                    break;
                int left = s.top();
                s.pop();
                ans += (min(height[i],height[left]) - height[top])*(i - left - 1);
            }
            s.push(i);
        }
        return ans;
    }
};
int main(){
    Solution ss;
    vector <int> arr{0,1,0,2,1,0,1,3,2,1,2,1};
    
    cout << ss.trap2(arr);
    return 0;
}