class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* f = q.front();
                q.pop();
                if(i==size-1) ans.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return ans;
    }
};