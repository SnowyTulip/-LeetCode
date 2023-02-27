# include <vector>
# include <iostream>
# include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int indexi = 1,indexj = 0;
        for(auto num:pushed){
            s.push(num);
            while(!s.empty()&&s.top() == popped[indexj]){
                s.pop();
                indexj++;
            }
        }
    
        return s.empty();
    }
};

int main(){
    vector <int> pushed {1,2,3,4,5};
    vector <int> poped {4,5,3,2,1};
    Solution s;
    std::cout << s.validateStackSequences(pushed,poped);
    return 0;
}