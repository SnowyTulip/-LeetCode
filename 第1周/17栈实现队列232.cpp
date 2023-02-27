#include <stack>
using namespace std;
class MyQueue {
private:
    stack <int> s1,s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans;
        if(!s2.empty()){
            ans = s2.top();
            s2.pop();
            return ans;
        }
        else{
            while(!s1.empty()){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
                
            }
            return pop();
        }
    }
    
    int peek() {
        int ans;
        if(!s2.empty()){
            ans = s2.top();
            return ans;
        }
        else{
            while(!s1.empty()){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
                
            }
            return peek();
        }

    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */