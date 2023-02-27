struct Node{
    int val;
    Node *next = nullptr;
    Node *pre  = nullptr;
};
class MyCircularDeque {
private:
    int count = 0;
    int size;
    Node *front,*last;
    // Node start{-1,nullptr,nullptr};
public:
    MyCircularDeque(int k) {
        size = k;
        // front = &start;
        // last  = &start;
        front = nullptr;
        last = nullptr;
    }
    
    bool insertFront(int value) {
        if (count == size)
            return false;
        Node *ptr = front;
        front = new Node{value,ptr};
        if(count == 0)
            last = front;
        else
            ptr -> pre = front;
        count ++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count == size)
            return false;
        Node *ptr = last;
        last = new Node{value,nullptr,ptr};
        if(count == 0)
            front = last;
        else
            ptr -> next = last;
        count ++;
        return true;
    }
    
    bool deleteFront() {
        if(count == 0)
            return false;
        Node *ptr = front;
        front = front->next;
        if (count == 1)
            last = nullptr;
        else
            front -> pre = nullptr;
        delete ptr;
        count --;
        return true;
    }
    
    bool deleteLast() {
        if(count == 0)
            return false;
        Node *ptr = last;
        last = last ->pre;
        if(count == 1)
            front = nullptr;
        else
            last -> next = nullptr;
        delete ptr;
        count--;
        return true;
    }
    
    int getFront() {
        if (count == 0)
            return -1;
        else
            return front -> val;
    }
    
    int getRear() {
        if (count == 0)
            return -1;
        else
            return last -> val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};
