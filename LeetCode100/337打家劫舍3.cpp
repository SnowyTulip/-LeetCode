#include <vector>
#include <map>
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
    map<TreeNode*,int> dic;
public:
    int rob(TreeNode* root) {
        if(dic.count(root))
            return dic[root];
        int res = 0;
        if(root){
            int val1 = 0,val2 = 0,val3 = 0,val4 = 0;
            if(root->left)
                val1 = rob(root->left->left)+rob(root->left->right);
            if(root->right)
                val2 = rob(root->right->left)+rob(root->right->right);
            res = root->val+val1+val2;
            val3 = rob(root->left);
            val4 = rob(root->right);
            res = max(res,val3+val4);
        }
        dic[root] = res;
        return res;
    }
};