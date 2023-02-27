#include <iostream>
#include <algorithm>
using namespace std;

void get_next(int *next,string &s){
    int n = s.size();
    int j = -1;
    next[0] = -1;
    for(int i = 1;i < n;++i){
        while(j != -1 && s[i] != s[j+1]){
            j = next[j];
        }
        if(s[i] == s[j+1])
            j++;
        next[i] = j;
    }
}
int KMP(string &s,string &pattern){
    int n = s.size(),m = pattern.size();
    if(n == 0 || m == 0) return -1;
    int *next = new int[m];
    get_next(next,pattern);
    int j = -1,res = -1;
    for(int i = 1;i < s.size();++i){
        while(j != -1 && s[i] != pattern[j+1]){
            j = next[j];
        }
        if(s[i] == pattern[j+1])
            j++;
        if(j == m-1){
            res = i;
            break;
        }
    }
    return res;
}