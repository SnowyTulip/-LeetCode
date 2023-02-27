#define NULL nullptr
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *sp = head,*fp = head;
        do {
            
            if (fp == NULL || fp->next == NULL)
                return NULL;
            sp = sp -> next;
            fp = fp -> next-> next;
        }while(sp!=fp);
        fp = head;
        while(sp!=fp){
            sp = sp ->next;
            fp = fp -> next;
        }
        return fp;
    
    }
};