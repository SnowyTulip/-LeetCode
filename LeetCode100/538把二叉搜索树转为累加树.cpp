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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode *cur = root;
        stack <TreeNode *> s;
        int val = 0;
        while(cur || s.size()){
            if(cur){
                s.push(cur);
                cur = cur -> right;
            }
            else{
                cur = s.top();
                val += cur -> val;
                cur -> val = val;
                s.pop();
                cur = cur -> left;
            }
        }
        return root;
        
    }
};