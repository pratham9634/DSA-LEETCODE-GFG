class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void helper(TreeNode* root){
        if(!root) return ;
        if(root->left){
            mp[root->left] = root;
            helper(root->left);
        }
        if(root->right){
            mp[root->right] = root;
            helper(root->right);
        }
    }
    void solve(TreeNode* t,int k ,vector<int>&ans){
        queue<TreeNode*> q;
        q.push(t);
        unordered_set<int> vis;
        vis.insert(t->val);
        while(!q.empty()){
            int n = q.size();
            if(k==0)break;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left->val)){
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                } 
                if(curr->right && !vis.count(curr->right->val)){
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                } 
                 if(mp.count(curr) && !vis.count(mp[curr]->val)) {
                    q.push(mp[curr]);
                    vis.insert(mp[curr]->val);
                }
            }
            k--;    
        }

         while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        helper(root);
        solve(target,k,ans);
        return ans;
    }
};