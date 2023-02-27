#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return is_s(root->left,root->right);
    }
    bool is_s(TreeNode *l,TreeNode *r){
        bool res = false;
        if(l && r)
            res = l->val == r->val  && is_s(l->left,r->right)
                                    && is_s(l->right,r->left);
        else
            res = l == nullptr && r == nullptr;
        return res;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *>q;
        int n;
        q.push(root);
        vector <TreeNode *>vec;
        int l,r;
        while(q.size()){
            n = q.size();
            for(int i = 0;i < n;++i){
                vec.push_back(q.front()->left);
                vec.push_back(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            l = 0;r = vec.size()-1;
            while(l <= r){
                if(vec[l] && vec[r]){
                    if(vec[l]->val != vec[r]->val)
                        return false;
                }
                else
                    if(vec[l] || vec[r])
                        return false;
                
                l++;
                r--;
            }
            vec.clear();
        }
        return true;
    }
    
};