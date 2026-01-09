class Solution {
public:
    pair<int,TreeNode*> dfs(TreeNode* root){
        if(!root) return {0,NULL};
        auto [d1,r1] = dfs(root->left);
        auto [d2,r2] = dfs(root->right);

        return {max(d1,d2)+1,d1==d2?root:d1>d2?r1:r2};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};