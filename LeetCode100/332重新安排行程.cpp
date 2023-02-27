#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution {
    vector<vector <string>> result;
    vector<string> path;
    int tickets_n = 0;
    bool end_flag = false;
    void backtracking(map <pair<string,string>,int> &dict,string curent){
        if(tickets_n == 0){
            result.push_back(path);
            end_flag = true;
            return;
        }
        else{
            for(auto &pack : dict){
                if(pack.second && pack.first.first == curent){
                    pack.second --;
                    path.push_back(pack.first.second);
                    tickets_n--;
                    backtracking(dict,pack.first.second);
                    tickets_n++;
                    pack.second++;
                    path.pop_back();
                }
                if(end_flag)
                    break;
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map <pair<string,string>,int> dict;
        for(auto &ticket:tickets)
            dict[pair<string,string>{ticket[0],ticket[1]}]++;
        tickets_n = tickets.size();
        path.push_back("JFK");
        backtracking(dict,"JFK");
        return result[0];
    }
};