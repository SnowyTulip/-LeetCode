#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        reverse(g.begin(),g.end());
        reverse(s.begin(),s.end());
        int indexi = 0,indexj = 0;
        int n = s.size(),m = g.size();
        while(indexi < n && indexj < m){
            while(indexj < m && g[indexj] > s[indexi])
                indexj++;
            indexj++;
            indexi++;
        }
        if(indexj > m)
            indexi --;
        return indexi;
    }
};
