#include <unordered_map>
#include <algorithm>
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
    unordered_map<TreeNode*,int> dic_h;
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        get_h(root);
        if(root) 
            res =  abs(dic_h[root->left]-dic_h[root->right]) <= 1 
                && isBalanced(root->left)
                && isBalanced(root->right); 
        return res;
    }
    int get_h(TreeNode* root){
        if(dic_h.count(root) == 0)
            dic_h[root] = root ? max(get_h(root->left),get_h(root->right))+1:0;
        return dic_h[root];
    }
};