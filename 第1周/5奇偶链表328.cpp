
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *sptr1 = new ListNode(-1,nullptr),*sptr2 = sptr1;
        ListNode *lptr1 = new ListNode(-1,nullptr),*lptr2 = lptr1;
        ListNode *ptr = head;
        int count = 1;
        while(ptr){
            if(count%2){
                sptr2 -> next = ptr;
                sptr2 = ptr;
            }
            else{
                lptr2 ->next = ptr;
                lptr2 = ptr;
            }
            count++;
            ptr = ptr -> next;
        }
        sptr2 -> next = lptr1 -> next;
        lptr2 ->next = nullptr;
        return sptr1 -> next;
    }
};