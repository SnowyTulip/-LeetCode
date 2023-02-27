#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue <Node *>q;
        if(root) q.push(root);
        Node *fp,*np;
        int n;
        while(!q.empty()){
            n = q.size();
            fp = q.front();
            q.pop();
            if(fp->left) q.push(fp->left);
            if(fp->right)q.push(fp->right);
            for(int i = 1;i < n;++i){
                np = q.front();
                q.pop();
                fp->next = np;
                fp = np; 
                if(fp->left) q.push(fp->left);
                if(fp->right)q.push(fp->right);
            }

        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        _connect(root,nullptr);
        return root;
    }
    void _connect(Node *left,Node *right){
        if(left){
            left -> next = right;
            _connect(left->left,left->right);
            if(right){
                _connect(left->right,right->left);
                _connect(right->left,right->right);
            }
        }
    }
};