
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*lp1 = list1 ,*lp2 = list2;
        ListNode*head = nullptr,*ptr;
        ListNode a;
        ptr = &a;
        while(true){
            if(lp1 == nullptr && lp2 == nullptr){
                break;
            }
            else if(lp1 == nullptr){
                if(head == nullptr)
                    head = lp2;
                ptr -> next = lp2;
                break;
            }
            else if(lp2 == nullptr){
                if(head == nullptr)
                    head = lp1;
                ptr -> next = lp1;
                break;
            }
            if(lp1->val < lp2 -> val){
                if(head == nullptr)
                    head = lp1;
                ptr -> next = lp1;
                lp1 = lp1 -> next;
                ptr = ptr ->next;
            }
            else{
                if(head == nullptr)
                    head = lp2;
                ptr -> next = lp2;
                lp2 = lp2 -> next;
                ptr = ptr ->next;
            }

        }
        return head;

    }
};