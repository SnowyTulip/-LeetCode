#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> result;
        if(array.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
            
        stack<int> s1,s2;
        int flag = 1;
        for(int i = 0;i < array.size();++i){
            if(!s1.empty()&&array[i] < array[s1.top()]){
                while(array[i] > array[s1.top()]){
                    s1.pop();
                    flag = 0;
                }
            }
            if(flag)
                s1.push(i);
        }
        flag = 1;
        for(int i = array.size()-1;i >= 0;i--){
            if(!s2.empty()&&array[i] > array[s2.top()]){
                while(array[i] < array[s2.top()]){
                    s2.pop();
                    flag = 0;
                }
            }
            if(flag)
                s2.push(i);
        }
        result.push_back(s1.top());
        result.push_back(s2.top());
        return result;
    }
};
int main(){
    Solution ss;
    vector <int> arr = {1,3,9,7,5};
    arr = ss.subSort(arr);
    return 0;
}