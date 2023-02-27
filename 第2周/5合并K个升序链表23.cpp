#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* *arr = new ListNode* [n];
        for(int i = 0;i < n;++i)
            arr[i] = lists[i];
        int min_index = 0;
        ListNode* ptr = new ListNode,*head = ptr;
        int flag = 0;
        while(true){
            flag = 0;
            for(int i = 0;i < n;++i){
                if(arr[i]){
                    min_index = i;
                    flag = 1;
                }   
            }
            if(flag == 0)
                return head -> next;
            for(int i = 0;i < n;++i){
                if(arr[i] && arr[i] -> val < arr[min_index]->val)
                    min_index = i;
            }
            ptr->next = new ListNode{arr[min_index] -> val,nullptr};
            arr[min_index] = arr[min_index] -> next;
            ptr = ptr -> next;
        }
        return head->next;
    }
};