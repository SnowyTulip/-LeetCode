#include <iostream>
using namespace std;
struct  node{
    int val;
    node *next;
    node *next_min = nullptr;//设置一个链，用来递减的链接链栈中的最小元素
};

class MinStack {
private:
    node *last_min;//递减的链栈
    node *head;
public:
    MinStack() {
    head = nullptr;
    }
    void push(int val) {
        head = new node{val,head};
        if(head->next == nullptr)
            last_min = head; 
        else if(val < last_min -> val){
            head->next_min = last_min;
            last_min = head;
        }
    }
    
    void pop() {
        node *ptr = head;
        if(head == last_min)
            last_min = last_min -> next;
        head = head -> next;
        delete ptr;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return last_min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    MinStack s;
    s.push(-2);
    cout << s.getMin() << "\n";
    s.push(0);
    s.push(-3);
    cout << s.getMin() <<"\n";
    s.pop();
    cout << s.getMin() << "\n";
}