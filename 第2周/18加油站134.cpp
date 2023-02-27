#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector <int> go(gas);
        for(int i = 0;i < n;++i)
            go[i] -= cost[i];
        int left = 0,count,flag;
        int index = 0;
        while(index < n){
            left += go[index];
            if(left >= 0){//注意剪枝操作
                count = index+1;
                flag = 1;
                while(count%n != index){
                    left += go[count%n];
                    if(left >= 0)
                        count += 1;
                    else{
                        if(count < n - 1){
                            index = count+1;
                            left = 0;
                            flag = 0;
                            break;
                        }
                        else
                            return -1;
                    }
                }
                if(flag)
                    return index;
            }
            else{
                left = 0;
                index++;
            }
        }
        return -1;
        
    }
};