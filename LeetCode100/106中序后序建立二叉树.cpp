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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * resp;
        if(inorder.size() == 0) return nullptr;
        int root_val = postorder[postorder.size()-1];
        resp = new TreeNode{root_val,nullptr,nullptr};
        for(int i = 0;i < inorder.size();++i){
            if(inorder[i] == root_val){
                vector<int> vec0{inorder.begin(),inorder.begin()+i};
                vector<int> vec1{inorder.begin()+i+1,inorder.end()};
                vector<int> vec2{postorder.begin(),postorder.begin()+i};
                vector<int> vec3{postorder.begin()+i,postorder.end()-1};
                resp -> left  = buildTree(vec0,vec2);
                resp -> right = buildTree(vec1,vec3);
                break;
            }
        }
        return resp;
    }
};