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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto p =  _isValidBST(root);
        return p.first <= p.second;
    }
    pair<int,int> _isValidBST(TreeNode *root){
        //pair<min,max>
        if(root -> left == nullptr && root -> right == nullptr)
            return pair<int,int>{root->val,root->val};
        pair<int,int> res{root->val,root->val},lpack,rpack;
        if(root->left){
            lpack = _isValidBST(root->left);
            if(root->val <= lpack.second || lpack.first > lpack.second 
                                        || root->val <= root->left->val){
                return pair<int,int>{10,0};
            }
            res.first = min(res.first,lpack.first);
            res.second = max(lpack.second,res.second);
        }
        if(root->right){
            rpack = _isValidBST(root->right);
            if(root->val >= rpack.first || rpack.first > rpack.second
                                        || root->val >= root->right->val){
                return pair<int,int>{10,0};
            }
            res.first = min(res.first,rpack.first);
            res.second = max(rpack.second,res.second);
        }
        return res;
    }
};
//中序遍历版本，一个二叉搜索树的中序遍历，一定是升序的！！！！！！！！！！！！！！！！！
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *cur = root;
        stack <TreeNode *> ss;
        double last = -(1 << 30);
        last *= 1000;
        bool res = true;
        while(cur || ss.size()){
            if(cur){
                ss.push(cur);
                cur = cur -> left;
            }
            else{
                cur = ss.top();
                if(cur->val <= last){
                    res = false;
                    break;
                }
                last = cur -> val;
                ss.pop();
                cur = cur-> right;
            }
        }
        return res;
    }
};