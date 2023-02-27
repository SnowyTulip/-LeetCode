#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector <int> cnts(ratings.size(),1);
        for(int i = 1;i < ratings.size();++i){
            if(ratings[i] > ratings[i-1]){
                cnts[i] = cnts[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2;i >= 0;--i){
            if(ratings[i] > ratings[i+1]){
                cnts[i] = max(cnts[i],cnts[i+1]+1);
            }
        }
        int result = 0;
        for(auto i:cnts)
            result += i;
        return result;
    }
};