#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string &s,int start){
        if(start == s.size()){
            result.push_back(path);
            return;
        }
        else{
            for(int len:getnext(s.substr(start))){
                path.push_back(s.substr(start,len));
                backtracking(s,start + len);
                path.pop_back();
            }
        }
    }
    bool is_back(string s){
        string str = s;
        reverse(str.begin(),str.end());
        return str == s;
    }
    vector<int> getnext(string s){//vec中表明的是长度
        vector <int> res;
        for(int i = 1;i <= s.size();++i){
            if(is_back(s.substr(0,i))){
                res.push_back(i);
            }
        }
        return res;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s,0);
        return result;   
    }
};