#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode s(-1,head);
        ListNode *ptr = &s,*str = ptr,*tpr1,*tpr2;
        while(str){
            for(int i = 0;i < k; ++i){
                if(str)
                    str = str -> next;
                else
                    return nullptr;
            }
            tpr2 = str -> next;
            reserve(ptr->next,str);
            tpr1 = ptr->next;
            ptr->next = str;
            tpr1 -> next = tpr2;
            ptr = tpr1;
            str = tpr1;
        }
        return s.next;
            
    }
    ListNode* reserve(ListNode* &head,ListNode* &tail){
        ListNode *ptr,*str,*tpr;
        ptr = head;
        str = head->next;
        while(ptr != tail){
            tpr = str->next;
            str -> next = ptr;
            ptr = str;
            str = tpr;
        }
        return tail;
    }
};
int main(){
    int arr[] = {1,2,3,4,5};
    ListNode *List = new ListNode{-1,nullptr};
    ListNode *ptr = List;
    for(int i = 0;i < 5;++i){
        ptr->next = new ListNode{arr[i],nullptr};
        ptr = ptr->next;
    }
    Solution s;
    s.reverseKGroup(List->next,2);
    ptr = List -> next;
    while(ptr){
        cout << ptr->val <<" ";
    }
}