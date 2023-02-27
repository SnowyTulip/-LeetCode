#include <vector>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> arr; 
        while(n){
            arr.push_back(n % 10);
            n/=10;
        }
        int l = 0;
        for(int i = 1;i < arr.size();++i){
            if(arr[i] > arr[i-1]){
                l = i;
                arr[i]--;
            }
        }
        if (arr.size() && arr[arr.size()-1] == 0)
            arr.pop_back();
        int res = 0;
        for(int i = arr.size()-1;i >= 0;--i){
            res *= 10;
            if(i >= l)
                res += arr[i];
            else
                res += 9;
        }
        return res;
    }
};