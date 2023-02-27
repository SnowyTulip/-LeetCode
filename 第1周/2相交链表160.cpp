
#include <map>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *fa = headA,*fb= headB;
        int count1 = 0,count2 = 0;
        while(fa){
            fa = fa -> next;
            count1 ++;
        }
        while(fb){
            fb = fb ->next;
            count2++;
        }
        ListNode *ptr1,*ptr2;
        int gap;
        if(count1 > count2){
            ptr1 = headA;
            ptr2 = headB;
            gap = count1 -count2;
        }
        else{
            ptr1 = headB;
            ptr2 = headA;
            gap = count2 - count1;
        }
        while(ptr1){
            if(gap>0){
                gap--;
                ptr1 = ptr1->next;
                continue;
            }
            if(ptr1 != ptr2){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next; 
            }
            else{
                return ptr1;
            }
        }
        return NULL;
    }
};
///使用快慢指针的解法：
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //需要将链表B改成环状结构，然后再使用快慢指针求解后改回
        ListNode *fastptr = headA,*slowptr = headA,*lastptr = headB;
        while(lastptr -> next){
            lastptr = lastptr -> next;
        }
        //构建成环形链表
        lastptr -> next = headB;

        //使用快慢指针找到环形链表第一个公共结点
        while(fastptr!= nullptr &&fastptr -> next != nullptr){//只用判断快指针是否到终点,可以保证慢指针不会空置
            fastptr = fastptr -> next -> next;
            slowptr = slowptr -> next;
            if(fastptr == slowptr){
                fastptr = headA;
                while(fastptr != slowptr){
                    fastptr = fastptr-> next;
                    slowptr = slowptr -> next;
                }
                lastptr -> next  = nullptr;
                return fastptr;
            }
        }
        lastptr -> next = nullptr;
        return nullptr;

    }
};
