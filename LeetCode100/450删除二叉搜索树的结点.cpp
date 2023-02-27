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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        TreeNode *resp = root;
        if(root->val == key){
            if(root->left == nullptr && root -> right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left && root->right){
                if(root->right->left){
                    resp = root->right->left;
                    while(resp -> left)
                        resp = resp->left;
                    root->val = resp -> val;
                    deleteNode(root->right,resp->val);
                    return root;
                }
                else{
                    resp = root -> right;
                    resp ->left = root -> left;
                    delete root;
                    return resp;
                }
            }
            else if (root -> right){
                resp = root -> right;
                delete root;
                return resp;
            }
            else if (root -> left){
                resp = root->left;
                delete root;
                return resp;
            }
        }
        else if(key > root->val){
            root-> right = deleteNode(root->right,key);
        }
        else{
            root-> left =deleteNode(root->left,key);
        }
        return root;
    }
};