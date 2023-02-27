#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first_ptr,*last_ptr;
        first_ptr = head;
        last_ptr = head->next;
        first_ptr -> next = nullptr;
        while(last_ptr!=nullptr){
            last_ptr -> next = first_ptr;
            first_ptr = last_ptr;
            last_ptr = last_ptr->next;
        }
        return first_ptr;
    }
};
