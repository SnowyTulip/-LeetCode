#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,index = 1;
        int pre = prices[0];
        int tmp;
        int n = prices.size();
        while(index < n){
            //以最低价买入，以最高价卖出，循环往复
            //找到价格谷底买入
            if(pre > prices[index]){
                while(index < n && pre >= prices[index]){
                    pre = prices[index];
                    index++;
                }
            }
            tmp = pre;
            //找到价格高峰卖出
            if(index < n && pre < prices[index]){
                while(index < n && pre <= prices[index]){
                    pre = prices[index];
                    index ++;
                }
            }
            else if(index < n && prices[index] == pre){
                while(index < n && prices[index] == pre)
                    index++;
            }
            profit += (pre-tmp);
        }
        return profit;
    }
};