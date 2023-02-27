# define NULL 0
# include<map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//使用Hash表进行相关操作
//由于Random指针在新的链表中不好定位,因此可以考虑使用Hash表完成这一定位功能 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> dic;
        Node* fp = head,*new_head = new Node{-1},*last = new_head;
        while(fp){
            last -> next = new Node{fp->val};
            last = last -> next;
            dic[fp] = last;
            fp = fp -> next;
        }
        Node *ptr1 = new_head->next,*ptr2 = head;
        while(ptr1){
            ptr1->random = dic[ptr2];
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next; 
        }
        return new_head-> next;
    }
};