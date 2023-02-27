#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<string> res;
    vector<string> path;
    int size_ip = 0;
    void backtracking(string &s,int start){
        if(start >= s.size() || size_ip >= 4){
            if(size_ip == 4 && start == s.size())
                res.push_back(process(path));
            return;
        }
        else{
            for(int i = start;i < start + 3;++i){
                if(is_ip(s,start,i)){
                    path.push_back(s.substr(start,i-start+1));
                    size_ip ++;
                    backtracking(s,i+1);
                    path.pop_back();
                    size_ip--;
                }
            }
        }
    }
    bool is_ip(string s,int start,int i){ //[start,i]
        int size = i - start + 1;
        string str = s.substr(start,size);
        if(size == 1)
            return true;
        else if(size == 2){
            return str[0] != '0';
        }
        else{
            if(str[0] == '0')
                return false;
            int num = 0;
            for(int j = 0;j < 3;++j){
                num *= 10;
                num += (str[j] - '0');
            }
            // cout << num <<" :" << str << "\n";
            return num <= 255;
        }
        return true;
    }
    string process(vector <string> vec){
        string restr ="";
        for(int i = 0;i < vec.size();++i){
            restr += vec[i];
            restr.push_back('.');
        }
        restr.pop_back();
        return restr; 
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        path.clear();
        backtracking(s,0);
        return res;
    }
};