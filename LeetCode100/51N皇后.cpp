#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int **arr,int n,int start_h){
        if(path.size() >= n || start_h >= n){
            if(path.size() == n)
                result.push_back(path);
            return;
        }
        else{
            vector <pair<int,int>> p;
            for(int j = 0;j < n;++j){
                if(arr[start_h][j] == 0){
                    p = getp(arr,n,start_h,j);
                    path.push_back(j);
                    backtracking(arr,n,start_h+1);
                    path.pop_back();
                    for(auto &pox:p)//清除影响
                        arr[pox.first][pox.second] = 0;
                }
            }
        }
    }
    vector <pair<int,int>> getp(int **arr,int n,int x,int y){
        vector <pair<int,int>> res;
        for(int i = 0;i < n;++i){
            if(arr[i][y] == 0){
                arr[i][y] = 1;
                res.push_back(pair<int,int>{i,y});
            }
        }
        for(int j = 0;j < n;++j){
            if(arr[x][j] == 0){
                arr[x][j] = 1;
                res.push_back(pair<int,int>{x,j});
            }
        }
        int signx[4] = {-1,-1,+1,+1};
        int signy[4] = {-1,+1,-1,+1};
        for(int i = 0;i < 4;++i){
            int indexi = x,indexj = y;
            while(indexi >= 0 && indexi < n && indexj >=0 && indexj < n){
                if(arr[indexi][indexj] == 0)
                    res.push_back(pair<int,int>{indexi,indexj});
                arr[indexi][indexj] = 1;
                indexi += signx[i];
                indexj += signy[i];
            }
        }
        return res;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        path.clear();
        int **arr = new int* [n+1];
        for(int i = 0;i < n+1;++i) arr[i] = new int[n]{0};
        backtracking(arr,n,0);
        string str_o(n,'.'),ss;
        vector<vector<string>> res;
        vector<string> vec;
        for(auto &item:result){
            vec.clear();
            for(auto & indexj: item){
                ss = str_o;
                ss[indexj] = 'Q';
                vec.push_back(ss);
            }
            res.push_back(vec);
        }
        return res;
    }
};

