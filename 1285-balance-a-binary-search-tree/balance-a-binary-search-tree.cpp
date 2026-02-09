class Solution {
public:
    void solve(TreeNode* root,vector<int>&vec){
        if(root==NULL) return;

        solve(root->left,vec);
        vec.push_back(root->val);
        solve(root->right,vec);
    }
    TreeNode* solve2(int l,int r,vector<int>&vec){
        if(l>r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solve2(l,mid-1,vec);
        root->right = solve2(mid+1,r,vec);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        solve(root,vec);
        int l = 0, r= vec.size()-1;
        return solve2(l,r,vec);
    }
};