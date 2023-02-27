# include <vector>
using namespace std;
int exchange(int &a,int &b);
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int arr[] = {0,0,0};
        for(auto i:nums)
            arr[i] ++;
        nums.clear();
        for(int i= 0;i < 3;++i){
            for(int j = 0; j < arr[i] ; ++j)
                nums.push_back(i);
        }
    }
};