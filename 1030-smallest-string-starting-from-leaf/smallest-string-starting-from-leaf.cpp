class Solution {
public:
    void solve(TreeNode* root, string &ans, string curr) {
        if (!root) return;

        char ch = 'a' + root->val;
        curr = ch + curr;

        if (root->left == NULL && root->right == NULL) {
            ans = min(ans, curr);
        }

        solve(root->left, ans, curr);
        solve(root->right, ans, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "~"; 
        solve(root, ans, "");
        return ans;
    }
};