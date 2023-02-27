#include <vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int cnt_arr[1001]{0};
        for(auto i:arr1)
            cnt_arr[i]++;
        vector <int> res;
        for(int i = 0;i < arr2.size();++i){
            while(cnt_arr[arr2[i]]){
                res.push_back(arr2[i]);
                cnt_arr[arr2[i]]--;
            }
        }
        for(int i = 0; i < 1001;++i){
            while(cnt_arr[i]){
                res.push_back(i);
                cnt_arr[i]--;
            }
        }
        return res;
    }
};