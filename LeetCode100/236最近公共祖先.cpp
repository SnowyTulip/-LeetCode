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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return has(root,p,q).first;
    }
    pair<TreeNode *,int> has(TreeNode *root,TreeNode *p,TreeNode *q){
        if(root == nullptr) 
            return pair<TreeNode *,int>{nullptr,0};
        pair <TreeNode*,int> pa,pb;
        pa = has(root->left,p,q);
        if(pa.second == 2)
            return pa;
        pb = has(root->right,p,q);
        if(pb.second == 2)
            return pb;
        int cnt = 0;
        if(root == p || root == q)
            cnt = 1;
        if(pa.second == 1 && pb.second == 1)
            return pair<TreeNode*,int>{root,2};
        if((pa.second == 1 || pb.second == 1) && (cnt))
            return pair<TreeNode*,int>{root,2};
        return pair<TreeNode *,int>{nullptr,cnt+pa.second+pb.second};
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == q || root == p) 
            return root;
        TreeNode *left,*right;
        left = lowestCommonAncestor(root->left,p,q);
        right = lowestCommonAncestor(root->right,p,q);
        if(left && right || (left || right) && (root == p || root == q))
            return root;
        if(left)
            return left;
        if(right)
            return right;
        return nullptr;
    }
};