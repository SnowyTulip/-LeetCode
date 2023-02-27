# include <string>
using namespace std;
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        char j;
        stack<char> store;
        for(auto i:s){
            if(i == '(' || i == '{' || i == '[')
                store.push(i);
            else if(i == ')' || i == '}' || i == ']'){
                if (store.empty())
                    return false;
                j = store.top();
                if (j == '('&& i == ')' ||j == '{'&& i == '}' ||j == '['&& i == ']' )
                    store.pop();
                else
                    return false;

            }
        }
        if(store.empty())
            return true;
        else
            return false;
    }
};