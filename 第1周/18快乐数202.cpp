# include <math.h>
# include <iostream>
using namespace std;

int get_next(int n){
    int ans = 0;
    while(n){
        ans += (n%10) * (n%10);
        n /= 10;
    }
    return ans;
}
class Solution {
public:
    bool isHappy(int n) {
        int fast,slow;
        int num = get_next(n);
        fast = get_next(num);
        slow = num;
        while(fast != slow && fast != 1 ){
            fast = get_next(get_next(fast));
            slow = get_next(slow);
        }
        if(fast == 1)
            return true;
        else
            return false;
    }
};
int main(){
    Solution ss;
    std::cout << ss.isHappy(2);
    return 0;
}