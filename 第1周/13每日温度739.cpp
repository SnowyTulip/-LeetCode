#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> s;
        vector <int>arr(temperatures.size(),0);
        for(int i = 0;i < temperatures.size();++i){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                arr[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return arr;
    }
};
int main(){
    vector <int> a = {73,74,75,71,69,72,76,73};
    Solution m;
    m.dailyTemperatures(a);
    return 0;
}