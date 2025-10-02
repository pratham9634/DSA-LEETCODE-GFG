class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        TreeNode* head = root;
        queue<TreeNode*> q;
        q.push(head);

        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            for(int i=0;i<n;i++){

            TreeNode* h = q.front();
            q.pop();
            curr.push_back(h->val);
            if(h->left)q.push(h->left);
            if(h->right) q.push(h->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};