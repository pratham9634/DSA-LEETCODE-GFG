class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(root == NULL ) return NULL;

        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);

        int temp = max(max(lh,rh)+root->val,root->val);
        int res = max(temp , lh+rh+root->val);
        ans = max(ans,res);
        return temp;

    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};