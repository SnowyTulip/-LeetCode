#include <iostream>
using namespace std;
class Solution_ {
public:
    bool isSubsequence(string s, string t) {
        int indext = 0,indexs = 0;
        while(indexs < s.size()&&indext < t.size()){
            if(s[indexs] == t[indext]){
                indext++;
                indexs++;
            }
            else
                indext++;
        }
        return indexs == s.size();
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int map[26];
        for(int i = 0;i < 26;++i) map[i] = -1;
        for(int k = 0;k < t.size();++k)
            if(map[t[k] -'a'] == -1)
                map[t[k] - 'a'] = k;
        int flag = map[s[0]];
        for(int i = 0;i < s.size();++i){
            if(map[s[i]] != -1 && map[s[i]] < flag)
                flag = map[s[i]];
            else
                return false;
        }
        return true;
    }
};
