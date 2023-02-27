
// Deinition for singly-linked list.
struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *startptr = new ListNode(-1,head),*endptr;
        for(int i = 1;i < left;++i)
            startptr = startptr -> next;
        ListNode *ptr1 = startptr -> next,*ptr2 = ptr1 -> next,*tmptr;
        int count = left;
        while(left < right){
            tmptr = ptr2 -> next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = tmptr;
            left ++;
        }
        endptr = startptr -> next;
        startptr -> next = ptr1;
        endptr -> next = ptr2;
        return count == 1?startptr -> next: head; 
    }
};