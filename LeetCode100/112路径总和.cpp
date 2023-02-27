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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        queue <pair<TreeNode *,int>> q;
        q.push(pair<TreeNode *,int>{root,targetSum});
        pair<TreeNode*,int> pack;
        bool res = false;
        while(q.size()){
            pack = q.front();
            if(pack.first -> left == nullptr&& pack.first -> right == nullptr 
                                            && pack.first -> val == pack.second){
                res = true;
                break;
            }
            if(pack.first -> right) 
                q.push(pair<TreeNode *,int>{pack.first->right,pack.second - pack.first->val});
            if(pack.first -> left) 
                q.push(pair<TreeNode *,int>{pack.first->left,pack.second - pack.first->val});
            q.pop();
        }
        return res;

    }
};