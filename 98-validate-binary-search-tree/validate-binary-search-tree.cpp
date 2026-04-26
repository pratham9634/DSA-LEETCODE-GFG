
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }
    private:
    bool valid(TreeNode* node,long mn , long mx){
        if(!node) return true;

        if(!(node->val >mn && node->val <mx)) return false;

        return valid(node->left,mn,node->val) && valid(node->right,node->val,mx);
    }
};