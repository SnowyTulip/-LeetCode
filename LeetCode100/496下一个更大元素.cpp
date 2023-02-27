#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> dic;
        for(int i = 0;i < nums1.size();++i)
            dic[nums1[i]] = i;
        stack <int> s;
        vector <int> res(nums1.size(),-1);
        for(int i = 0;i < nums2.size();++i){
            while(!s.empty() && nums2[i] > nums2[s.top()]){
                if(dic.count(nums2[s.top()]))
                    res[dic[nums2[s.top()]]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};