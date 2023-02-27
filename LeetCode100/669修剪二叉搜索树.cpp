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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        TreeNode *resp = root;
        if(root->val <= high && root->val >= low){
            root -> left = trimBST(root->left,low,high);
            root -> right= trimBST(root->right,low,high);
        }
        else if(root->val > high){
            resp = root -> left;
            resp = trimBST(resp,low,high);
        }
        else if(root->val < low){
            resp = root -> right;
            resp = trimBST(resp,low,high);
        }
        return resp;
    }
};