class Solution {
public:

    void solve(TreeNode* root,vector<int>&vec){
        if(root==NULL) return;
        solve(root->left,vec);
        vec.push_back(root->val);
        solve(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>vec;
        TreeNode* node = root;
        solve(node,vec);

        int n  = vec.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(vec[i]+vec[j]==k) return true;
            }
        }
        return false;
    }
};