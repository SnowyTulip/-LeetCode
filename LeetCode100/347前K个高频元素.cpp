#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
struct cmp{
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        return p1.second > p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dic;
        for(int i = 0;i < nums.size();++i)
            dic[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> heap;
        int cnt = 0;
        for(auto &item:dic){
            if(cnt < k)
                heap.push(item);
            else{
                if(item.second > heap.top().second){
                    heap.pop();
                    heap.push(item);
                }
            }
            cnt++;
        }
        vector <int> res;
        while(!heap.empty()){
            res.push_back(heap.top().first);
            heap.pop();
        }
        return res;
    }
};