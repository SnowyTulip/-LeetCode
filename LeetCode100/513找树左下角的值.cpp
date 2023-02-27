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
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode *>q;
        q.push(root);
        int last_val;
        while(q.size()){
            last_val = q.front() -> val;
            if(q.front() -> right) q.push(q.front()->right);
            if(q.front() -> left)  q.push(q.front()-> left);
            q.pop();
        }
        return last_val;
    }
};