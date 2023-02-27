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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int p_begin,int p_end,int i_begin,int i_end){
        if(i_begin == i_end)
            return nullptr;
        int root_val = preorder[p_begin];
        TreeNode *root = new TreeNode{root_val,nullptr,nullptr};
        for(int i = 0;i+i_begin < i_end;++i){
            if(inorder[i+i_begin] == root_val){
                root->left  = buildTree(preorder,inorder,
                                        p_begin+1,p_begin+i+1,
                                        i_begin,i_begin+i);
                root->right = buildTree(preorder,inorder,
                                        p_begin+i+1,p_end,
                                        i_begin+i+1,i_end);
                break;
            }
        }
        return root;
    }
};