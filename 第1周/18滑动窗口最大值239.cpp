#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap;
        for(int i = 0;i < k;++i){
            pair<int,int> s(nums[i],i);
            heap.emplace(s);
        }
        vector<int> result;
        result.push_back(heap.top().first);
        for(int i = k;i < nums.size();++i){
            heap.emplace(nums[i],i);
            pair<int,int> s = heap.top();
            while( s.second <= i - k){
                heap.pop();
                s = heap.top();
            }
            result.push_back(s.first);
        }
        return result;
    }
};
