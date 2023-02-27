
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode s = ListNode{-1,head};
        ListNode *str =  &s;
        ListNode *ptr = head,*tmp,*dstr = str;
        while(ptr){
            if(ptr->val == val){
                tmp = ptr;
                ptr = ptr->next;
                delete tmp;
                str -> next = ptr;
            }
            else{
                ptr = ptr-> next;
                str = str -> next;
            }
        }
        return s.next;
    }
};