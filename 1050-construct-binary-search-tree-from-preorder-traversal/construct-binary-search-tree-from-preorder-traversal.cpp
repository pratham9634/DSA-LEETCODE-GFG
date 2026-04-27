class Solution {
public:
    TreeNode* solve(vector<int>&arr,int &i,int bound){
        if(i==arr.size() || arr[i]>bound) return NULL;
        
        TreeNode* root = new TreeNode(arr[i++]);
        root->left = solve(arr,i,root->val);
        root->right = solve(arr,i,bound);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return solve(preorder,i,INT_MAX);
    }
};