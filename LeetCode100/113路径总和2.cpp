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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <vector<int>> res;
        vector <int> vec;
        if(root == nullptr) return res;
        if(root->left == nullptr && root -> right == nullptr){
            if(root -> val == targetSum){
                vec.push_back(root->val);
                res.push_back(vec); 
            }
            return res;
        }
        for(auto &item:pathSum(root->left,targetSum - root->val)){
            item.insert(item.begin(),root->val);
            res.push_back(item);
        }
        for(auto &item:pathSum(root->right,targetSum - root->val)){
            item.insert(item.begin(),root->val);
            res.push_back(item);
        }
        return res;
    }
};