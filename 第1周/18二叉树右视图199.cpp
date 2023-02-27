#include <vector>
using namespace std;
 //Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode *ptr = root;
        vector <TreeNode *> Nodes,container;
        vector <int> view;
        if (root)
            Nodes.push_back(root);
        while(!Nodes.empty()){
            view.push_back(Nodes[Nodes.size()-1]->val);
            container = Nodes;
            Nodes.clear();
            for(auto node:container){
                if(node->left)
                    Nodes.push_back(node->left);
                if(node->right)
                    Nodes.push_back(node->right);
            }
        }
        return view;
    }
};