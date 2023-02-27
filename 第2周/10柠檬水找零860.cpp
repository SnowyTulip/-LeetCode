#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[] = {0,0,0};
        for(auto bill:bills){
            arr[bill/10] ++;
            if(bill == 5)
                continue;
            else if(bill == 10){
                if(arr[0] == 0)
                    return false;
                arr[0] --;
            }
            else if(bill == 20){//贪心算法，能找10块的，就不找5块的，因为5块的可以应付10元和20圆的
                if(arr[1] >= 1 && arr[0] >= 1){
                    arr[1] --;
                    arr[0]--;
                }
                if(arr[0] >= 3){
                    arr[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};