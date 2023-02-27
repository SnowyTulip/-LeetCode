
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *sptr1 = nullptr,*sptr2,*lptr1 = nullptr,*lptr2,*ptr = head;
        while(ptr){
            if(ptr -> val < x){
                if(lptr1 == nullptr){
                    lptr1 = ptr;
                    lptr2 = ptr;
                }
                else{
                    lptr2 -> next = ptr;
                    lptr2 = ptr;
                }
            }
            else{
                if(sptr1 == nullptr){
                    sptr1 = ptr;
                    sptr2 = ptr;
                }
                else{
                    sptr2 -> next = ptr;
                    sptr2 = ptr;
                }
            }
            ptr = ptr -> next;
        }
        if(sptr1)
            sptr2 -> next = nullptr;
        if(lptr1){
            lptr2 -> next = sptr1;
            return lptr1;
        }
        else{
            return sptr1;
        }
    }
};