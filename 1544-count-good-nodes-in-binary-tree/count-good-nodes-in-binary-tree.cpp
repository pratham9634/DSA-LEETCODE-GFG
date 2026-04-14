
class Solution {
public:
    void solve(TreeNode* root,int &ans,int cmax){
        if(root->val>=cmax) ans++;
        cmax = max(root->val,cmax);
        if(root->left) solve(root->left,ans,cmax);
        if(root->right) solve(root->right,ans,cmax);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        solve(root,ans,root->val);
        return ans;
    }
};