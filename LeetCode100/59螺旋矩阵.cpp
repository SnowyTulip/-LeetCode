#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int num = 1;
        int cnt = n;
        while (cnt > 0) {

            res[x][y] = num;

            for (int i = 0; i < cnt - 1; ++i) {
                y++;
                num++;
                res[x][y] = num; 
            }
            for (int i = 0; i < cnt-1; ++i) {
                x++;
                num++;
                res[x][y] = num;
            }
            for (int i = 0; i < cnt-1; ++i) {
                y--;
                num++;
                res[x][y] = num;
            }
            for (int i = 0; i < cnt - 2; ++i) {//last one (on left)
                x--;
                num++;
                res[x][y] = num;
            }
            y++;
            num++;
            cnt -= 2;
        }
        return res;
    }
};