#include <stack>
using namespace std;
// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *ptr = head;
        while(ptr){
            s.push(ptr->val);
            ptr = ptr -> next;
        }
        ptr = head;
        while(ptr&&!s.empty()){
            if(s.top() == ptr-> val){
                s.pop();
                ptr = ptr -> next;
            }
            else
                break;
        }
        return s.empty();
        
    }
};