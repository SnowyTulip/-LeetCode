#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> s; // 用数组当做栈
        string res = ""; // 存储最终的结果
        
        for (int i = 0; i < num.size(); i++) {
            int number = num[i] - '0'; // 将字符型的num转化为数字
            while (s.size() != 0 && s[s.size() - 1] > number && k > 0) {
                s.pop_back(); // 弹出栈尾元素
                k--;
            }
            if (number != 0 || s.size() != 0) {
                s.push_back(number);
            }
        }
        while (s.size() != 0 && k > 0) { // 如果栈不为空，仍然可以删除数字
            s.pop_back();
            k--;
        }
        for (int i = 0; i < s.size(); i++) { // 加入到res中
            res.append(1, s[i] + '0');
        }
        if (res == "") {
            res = "0";
        }
        return res;
    }
};
int main(){
    Solution s;
    s.removeKdigits("1432219",3);
    return 0;
}