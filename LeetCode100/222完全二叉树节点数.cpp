#include <math.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//二分查找+位运算版本
class Solution {
public:
    bool exist(TreeNode *root,int k){
        TreeNode *ptr = root;
        if(k == 1) return root != nullptr;
        int hx = int(log2(k));
        int bas = 1 << (hx-1);
        for(int i = 0;i < hx && ptr;++i){
            if(k & bas)
                ptr = ptr -> right;
            else
                ptr = ptr -> left;
            bas = bas >> 1;
        }
        return ptr != nullptr;
    }
    int countNodes(TreeNode* root) {
        TreeNode *cur = root;
        if(!root) return 0;
        int cnt = 0,l,r;
        while(cur){
            cur = cur -> left;
            cnt++;
        }
        l = 1 << (cnt-1);
        r = (1 << cnt) - 1;
        int mid,res = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(exist(root,mid)){
                if(exist(root,mid+1))
                    l = mid + 1;
                else{
                    res = mid;
                    break;
                }
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};