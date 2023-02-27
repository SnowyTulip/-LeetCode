#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root->left == nullptr && root -> right == nullptr)
            return vector<string>{to_string(root->val)};
        vector<string>res;
        if(root->left){
            for(auto &str:binaryTreePaths(root->left)){
                res.push_back(to_string(root->val) + "->"+ str);
            }
        }
        if(root->right){
            for(auto &str:binaryTreePaths(root->right)){
                res.push_back(to_string(root->val) + "->"+ str);
            }
        }
        return res;
    }
};