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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums.begin(),nums.end());
    }
    TreeNode* construct(vector<int>::iterator begin,vector<int>::iterator end){
        if(begin == end)
            return nullptr;
        auto max_iter = max_element(begin,end);
        TreeNode *root = new TreeNode{*max_iter,nullptr,nullptr};
        root -> left = construct(begin,max_iter);
        root -> right= construct(max_iter+1,end);
        return root;
    }
};