class Solution {
public:
    void solve(TreeNode* root,int &ans,int sum){
        if(!root) return ;
        sum = sum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans += sum;
            return;
        }
        if(root->left) solve(root->left,ans,sum);
        if(root->right) solve(root->right,ans,sum);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root,ans,0);
        return ans;
    }
};