#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {//后序
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root){
            TreeNode *cur = root;
            TreeNode *lastr = nullptr;
            stack<TreeNode *>ss;
            while(cur || ss.size()){
                if(cur){
                    ss.push(cur);
                    cur = cur -> left;
                }
                else{
                    if(ss.top()->right == nullptr || ss.top()->right == lastr){
                        res.push_back(ss.top() -> val);
                        lastr = ss.top();
                        cur = nullptr;
                        ss.pop();
                    }
                    else{
                        cur = ss.top() -> right;
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {//前序
        vector <int> res;
        stack <TreeNode *> s;
        if(root) s.push(root);
        TreeNode *ptr;
        while(s.size()){
            ptr = s.top();
            res.push_back(ptr->val);
            s.pop();
            if(ptr -> right) s.push(ptr->right);
            if(ptr -> left ) s.push(ptr->left );
        }
        return res;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root){
            stack <TreeNode *>s;
            TreeNode * cur = root;
            while(cur != nullptr || s.size()){
                if(cur){
                    s.push(cur);
                    cur = cur -> left;
                }
                else{
                    cur = s.top();
                    s.pop();
                    res.push_back(cur->val);
                    cur = cur -> right;
                }
            }  
        }
        return res;
    }
};